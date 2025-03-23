/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:32:42 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/23 15:35:04 by rbaticle         ###   ########.fr       */
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
	pthread_t		t;
	int				id;
	int				eat_count;
	int				eating;
	int				*dead;
	int				nb_meals;
	int				nb_philo;
	size_t			t_death;
	size_t			t_eat;
	size_t			t_sleep;
	size_t			t_start;
	size_t			t_last_meal;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_data
{
	int				dead;
	int				nb_philo;
	int				nb_meals;
	size_t			t_sleep;
	size_t			t_eat;
	size_t			t_death;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}	t_data;

//	main.c
int			error(char *str, t_data *data);
//	init.c
int			init(t_data *data, int argc, char **argv);
//	start.c
int			start(t_data *data);
//	monitor.c
void		*monitor(void *data);
//	actions.c
int			get_dead(t_philo *philo);
void		message(char *str, t_philo *philo);
void		eat(t_philo *philo);
//	utils.c
int			check_input(char **argv);
int			ft_atoi(const char *str);
u_int64_t	get_time(void);
int			ft_usleep(useconds_t time);
int			ft_strcmp(const char *s1, const char *s2);

#endif
