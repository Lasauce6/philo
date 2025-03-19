/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:32:45 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/17 12:38:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_bool(t_mutex *mutex, bool *dest, bool value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *val)
{
	bool	res;

	mutex_handle(mutex, LOCK);
	res = *val;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

void	set_long(t_mutex *mutex, long *dest, long value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

long	get_long(t_mutex *mutex, long *val)
{
	long	res;

	mutex_handle(mutex, LOCK);
	res = *val;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

bool	end_simulation(t_data *data)
{
	return (get_bool(&data->mutex, &data->end));
}
