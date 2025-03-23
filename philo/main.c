/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:28:44 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/23 12:45:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_data(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (data->forks)
			pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->write_lock);
	clear_data(data);
}

int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (1);
	if (check_input(argv))
		return (1);
	if (init(&data, argc, argv))
		return (1);
	if (start(&data))
		return (1);
	ft_exit(&data);
	return (0);
}
