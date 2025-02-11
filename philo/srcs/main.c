/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:33 by rbaticle          #+#    #+#             */
/*   Updated: 2025/02/03 15:56:33 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_data	init_data(char **argv)
{
	t_data	data;


}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || ft_atoi(argv[1]) == 0 || argc > 6)
		return (printf("Error: usage -> ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"), 1);
	else
	{
		data = init_data(argv);
	}
	return (0);
}
