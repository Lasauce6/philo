/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:32:42 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/17 12:39:30 by rbaticle         ###   ########.fr       */
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
# include <limits.h>

typedef pthread_mutex_t	t_mutex;

typedef enum e_option
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_option;

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
	bool	ready;
	t_mutex	mutex;
	bool	end;
	t_fork	*forks;
	t_philo	*philos;
};

//	main.c
void	error_exit(char *msg, t_data *data);
//	init.c
t_data	*init_data(char **argv);
//	utils.c
int		ft_atoi(const char *str, t_data *data);
long	ft_atol(const char *str, t_data *data);
//	mutex_threads.c
int		mutex_handle(t_mutex *mtx, t_option option);
int		thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_option option);
//	free.c
void	free_data(t_data *data);
//	start.c
void	start(t_data *data);
//	getter_setters.c
bool	end_simulation(t_data *data);
long	get_long(t_mutex *mutex, long *val);
void	set_long(t_mutex *mutex, long *dest, long value);
bool	get_bool(t_mutex *mutex, bool *val);
void	set_bool(t_mutex *mutex, bool *dest, bool value);

#endif
