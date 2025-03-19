/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:41:26 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/14 18:22:59 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->forks)
	{
		while (data->nb_ph)
		{
			mutex_handle(&data->forks[data->nb_ph - 1].fork, DESTROY);
			data->nb_ph--;
		}
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	free(data);
}
