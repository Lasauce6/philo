/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:13:05 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/17 12:42:02 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	wait_for_threads(t_data *data)
{
	while (get_bool(&data->mutex, &data->ready) == false)
		;
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	wait_for_threads(philo->data);
	return (NULL);
}

void	start(t_data *data)
{
	int	i;

	i = -1;
	if (data->nb_eat == 0)
		return ;
	else if (data->nb_ph == 1)
		;// TODO:
	else
	{
		while (++i < data->nb_ph)
		{
			if (thread_handle(&data->philos[i].thread_id, simulation,
					&data->philos[i], CREATE))
				error_exit("Error creating threads\n", data);
		}
	}
	set_bool(&data->mutex, &data->ready, true);
}
