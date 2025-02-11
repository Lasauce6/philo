/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:32:42 by rbaticle          #+#    #+#             */
/*   Updated: 2025/02/03 16:21:28 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	t_mutex	fork;
	int		id;
}	t_fork;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	bool		full;
	long		last_eat_time;
	t_fork		*f_left;
	t_fork		*f_right;
	pthread_t	thread_id;
	t_data		*data;
}	t_philo;

struct s_data
{
	int		nb_ph;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		nb_eat;
	long	t_start;
	bool	end;
	t_fork	*forks;
	t_philo	*philos;
};

//	utils.c
int	ft_atoi(const char *str);

#endif
