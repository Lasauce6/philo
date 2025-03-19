/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:33 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/17 12:04:54 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_exit(char *msg, t_data *data)
{
	while (*msg++)
		write(STDERR_FILENO, msg, 1);
	free_data(data);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || ft_atoi(argv[1], NULL) <= 0 || argc > 6)
		return (printf("Error: usage -> ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"), 1);
	else
	{
		data = init_data(argv);
		if (data == NULL)
			return (printf("MALOC_ERROR"), 1);
		start(data);
	}
	return (0);
}
