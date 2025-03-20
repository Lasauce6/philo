/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:28:44 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/20 18:46:40 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clear_data(t_data *data)
{
	if (data->id)
		free(data->id);
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
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

static int	one_philo(t_data *data)
{
	data->t_start = get_time();
	if (pthread_create(&data->id[0], NULL, &routine, &data->philos[0]))
		return (error(THREAD_ERROR, data));
	pthread_detach(data->id[0]);
	while (data->dead == 0)
		ft_usleep(0);
	ft_exit(data);
	return (0);
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
	if (data.nb_philo == 1)
		return (one_philo(&data));
	if (start(&data))
		return (1);
	ft_exit(&data);
	return (0);
}
