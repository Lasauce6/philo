/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:38:08 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/17 12:27:05 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	assign_fork(t_philo *philo, t_fork *forks, int pos)
{
	int	nb_ph;

	nb_ph = philo->data->nb_ph;
	if (philo->id % 2 == 0)
	{
		philo->f_right = &forks[pos];
		philo->f_left = &forks[(pos + 1) % nb_ph];
	}
	else
	{
		philo->f_left = &forks[pos];
		philo->f_right = &forks[(pos + 1) % nb_ph];
	}
}

static void	init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->nb_ph)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->eat_count = 0;
		philo->data = data;
		assign_fork(philo, data->forks, i);
	}
}

static void	init_times(char **argv, t_data *data)
{
	data->end = false;
	data->ready = false;
	data->nb_ph = ft_atoi(argv[1], data);
	data->t_die = ft_atol(argv[2], data) * 1e3;
	data->t_eat = ft_atol(argv[3], data) * 1e3;
	data->t_sleep = ft_atol(argv[4], data) * 1e3;
	if (data->t_die < 6e4 || data->t_die < 6e4 || data->t_sleep < 6e4)
		error_exit("Need more than 60ms\n", data);
	if (argv[5])
		data->nb_eat = ft_atoi(argv[5], data);
	else
		data->nb_eat = -1;
}

t_data	*init_data(char **argv)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	init_times(argv, data);
	if (mutex_handle(&data->data_mutex, INIT))
		error_exit("Error creating a mutex", data);
	data->forks = malloc(sizeof(t_fork) * data->nb_ph);
	if (data->forks == NULL)
		return (free_data(data), NULL);
	i = -1;
	while (++i < data->nb_ph)
	{
		if (mutex_handle(&data->forks[i].fork, INIT))
			return (free_data(data), NULL);
		data->forks[i].id = i;
	}
	data->philos = malloc(sizeof(t_philo) * data->nb_ph);
	if (data->philos == NULL)
		return (free_data(data), NULL);
	init_philos(data);
	return (data);
}
