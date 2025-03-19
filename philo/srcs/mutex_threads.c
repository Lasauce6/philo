/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:20:38 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/17 12:32:27 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	mutex_handle(t_mutex *mtx, t_option option)
{
	if (option == LOCK)
		return (pthread_mutex_lock(mtx));
	if (option == UNLOCK)
		return (pthread_mutex_unlock(mtx));
	if (option == INIT)
		return (pthread_mutex_init(mtx, NULL));
	if (option == DESTROY)
		return (pthread_mutex_destroy(mtx));
	return (-1);
}

int	thread_handle(pthread_t *thread, void *(*foo)(void *),
				void *data, t_option option)
{
	if (option == CREATE)
		return (pthread_create(thread, NULL, foo, data));
	if (option == JOIN)
		return (pthread_join(*thread, NULL));
	if (option == DETACH)
		return (pthread_detach(*thread));
	return (-1);
}
