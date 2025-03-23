/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:24:51 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/23 16:17:04 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = (int) ft_atoi(argv[1]);
	data->t_death = (size_t) ft_atoi(argv[2]);
	data->t_eat = (size_t) ft_atoi(argv[3]);
	data->t_sleep = (size_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_meals = (int) ft_atoi(argv[5]);
	else
		data->nb_meals = -1;
	if (data->nb_philo <= 0 || data->nb_philo > 200)
		return (error(VAL_ERROR, NULL));
	data->dead = 0;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	return (0);
}

static int	alloc(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (error(MALLOC_ERROR, data));
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (error(MALLOC_ERROR, data));
	return (0);
}

static int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->nb_philo - 1];
	i = 0;
	while (++i < data->nb_philo)
	{
		if (i % 2 == 0)
		{
			data->philos[i].l_fork = &data->forks[i];
			data->philos[i].r_fork = &data->forks[i - 1];
		}
		else
		{
			data->philos[i].r_fork = &data->forks[i];
			data->philos[i].l_fork = &data->forks[i - 1];
		}
	}
	return (0);
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].t_death = data->t_death;
		data->philos[i].t_eat = data->t_eat;
		data->philos[i].t_sleep = data->t_sleep;
		data->philos[i].nb_meals = data->nb_meals;
		data->philos[i].nb_philo = data->nb_philo;
		data->philos[i].eat_count = 0;
		data->philos[i].eating = 0;
		data->philos[i].t_start = get_time();
		data->philos[i].t_last_meal = get_time();
		data->philos[i].dead_lock = &data->dead_lock;
		data->philos[i].meal_lock = &data->meal_lock;
		data->philos[i].write_lock = &data->write_lock;
		data->philos[i].dead = &data->dead;
		i++;
	}
}

int	init(t_data *data, int argc, char **argv)
{
	if (init_data(data, argc, argv))
		return (1);
	if (alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (0);
}
