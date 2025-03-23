/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:46:51 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/23 15:35:19 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_exec(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!get_dead(philo))
		eat(philo);
	return (NULL);
}

int	start(t_data *data)
{
	pthread_t	supervisor;
	int			i;

	if (pthread_create(&supervisor, NULL, &monitor, data->philos) != 0)
		error(THREAD_ERROR, data);
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_create(&data->philos[i].t, NULL, &philo_exec,
				&data->philos[i]) != 0)
			error(THREAD_ERROR, data);
	}
	i = -1;
	if (pthread_join(supervisor, NULL) != 0)
		error(JOIN_ERROR, data);
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->philos[i].t, NULL) != 0)
			error(JOIN_ERROR, data);
	}
	return (0);
}
