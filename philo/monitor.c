/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:51:25 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/24 12:38:41 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_dead(t_philo *philo, size_t t_death)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->t_last_meal >= t_death && philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

static int	check_dead(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].nb_philo)
	{
		if (philo_dead(&philos[i], philos[i].t_death))
		{
			message(DIED, &philos[i]);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
	}
	return (0);
}

static int	check_all_ate(t_philo *philos)
{
	int	i;
	int	all_ate;

	all_ate = 0;
	if (philos[0].nb_meals == -1)
		return (0);
	i = -1;
	while (++i < philos[0].nb_philo)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].eat_count >= philos[i].nb_meals)
			all_ate++;
		pthread_mutex_unlock(philos[i].meal_lock);
	}
	if (all_ate == philos[0].nb_philo)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *data)
{
	t_philo	*philos;

	philos = (t_philo *) data;
	while (1)
	{
		if (check_dead(philos) || check_all_ate(philos))
			break ;
	}
	return (NULL);
}
