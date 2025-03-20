/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:46:51 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/21 00:13:55 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*check_dead(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->end >= philo->data->nb_philo)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

static void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->t_death && philo->eating == 0)
			message(DIED, philo);
		if (philo->eat_count == philo->data->nb_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->end++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	philo->t_death = philo->data->t_death + get_time();
	if (pthread_create(&philo->t, NULL, &supervisor, (void *)philo))
		return ((void *) 1);
	while (philo->data->dead == 0)
	{
		eat(philo);
		message(THINKING, philo);
	}
	if (pthread_join(philo->t, NULL))
		return ((void *) 1);
	return (NULL);
}

int	start(t_data *data)
{
	int			i;
	pthread_t	t;

	i = -1;
	data->t_start = get_time();
	if (data->nb_meals > 0)
	{
		if (pthread_create(&t, NULL, &check_dead, &data->philos[0]))
			return (error(THREAD_ERROR, data));
	}
	while (++i < data->nb_philo)
	{
		if (pthread_create(&data->id[i], NULL, &routine, &data->philos[i]))
			return (error(THREAD_ERROR, data));
		ft_usleep(1);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->id[i], NULL))
			return (error(JOIN_ERROR, data));
	}
	return (0);
}
