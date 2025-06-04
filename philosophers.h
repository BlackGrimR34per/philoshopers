/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/04 11:24:50 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define INVALID_ARGS "Invalid number of arguments\n"

typedef enum e_time_measurement
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}	t_time_measurement;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	long			last_meal;
	bool			is_alive;
	struct s_utils	*util;
	pthread_t		thread;
}	t_philo;

typedef struct s_utils
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_philo_must_eat;
	int				must_eat;
	long			simulation_start;
	bool			threads_ready;
	bool			simulation_has_ended;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	t_fork			*forks;
	t_philo			*philos;
}	t_utils;

void	check_initialisers(int argc, t_utils *utils, char *argv[]);
void	*death_monitor(void *args);
void	free_utils(t_utils *util);
long	ft_atol(char *str);
int		ft_isdigit(char c);
void	init_utils(int argc, t_utils *utils, char *argv[]);
void	init_philos(t_utils *util);
int		print_error(char *error_message);
void	print_status(t_utils *util, int id, char *message);
void	precise_sleep(long usec, t_utils *util);
void	*start_routine(void *args);
void	start_eating(t_utils *util, t_philo *philo);
void	start_sleeping(t_utils *util, t_philo *philo);
long	get_time(t_time_measurement time_measurement);

#endif