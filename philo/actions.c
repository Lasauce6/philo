/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:29:58 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/23 15:40:30 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	message(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->t_start;
	if (!get_dead(philo))
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	message(TAKE_FORKS, philo);
	if (philo->nb_philo == 1)
	{
		ft_usleep(philo->t_death);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	message(TAKE_FORKS, philo);
	philo->eating = 1;
	message(EATING, philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->t_last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->t_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	message(SLEEPING, philo);
	ft_usleep(philo->t_sleep);
	message(THINKING, philo);
}
