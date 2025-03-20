/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:32:42 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/20 20:34:59 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define INPUT_ERROR "Input Error"
# define VAL_ERROR "Wrong Values"
# define MALLOC_ERROR "Malloc Error"
# define THREAD_ERROR "Error creating Thread"
# define JOIN_ERROR "Error joining Thread"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define TAKE_FORKS "has taken a fork"
# define DIED "died"

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t;
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	u_int64_t		t_death;
	pthread_mutex_t	lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*id;
	int				nb_philo;
	int				nb_meals;
	int				dead;
	int				end;
	t_philo			*philos;
	u_int64_t		t_death;
	u_int64_t		t_eat;
	u_int64_t		t_sleep;
	u_int64_t		t_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

//	main.c
int			error(char *str, t_data *data);
//	init.c
int			init(t_data *data, int argc, char **argv);
//	start.c
int			start(t_data *data);
void		*routine(void *data);
//	actions.c
void		message(char *str, t_philo *philo);
void		eat(t_philo *philo);
//	utils.c
int			check_input(char **argv);
int			ft_atoi(const char *str);
u_int64_t	get_time(void);
int			ft_usleep(useconds_t time);
int			ft_strcmp(const char *s1, const char *s2);

#endif
