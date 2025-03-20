/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:24:51 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/20 20:37:25 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = (int) ft_atoi(argv[1]);
	data->t_death = (u_int64_t) ft_atoi(argv[2]);
	data->t_eat = (u_int64_t) ft_atoi(argv[3]);
	data->t_sleep = (u_int64_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_meals = (int) ft_atoi(argv[5]);
	else
		data->nb_meals = -1;
	if (data->nb_philo <= 0 || data->nb_philo > 200)
		return (error(VAL_ERROR, NULL));
	data->dead = 0;
	data->end = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

static int	alloc(t_data *data)
{
	data->id = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->id)
		return (error(MALLOC_ERROR, data));
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
	i = 0;
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->nb_philo - 1];
	i = 1;
	while (i < data->nb_philo)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].t_death = data->t_death;
		data->philos[i].eat_count = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
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
