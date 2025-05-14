/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/14 20:04:40 by yosherau         ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			meals_eaten;
	long		last_meal;
	bool		is_alive;
	pthread_t	thread;
}	t_philo;

typedef struct s_utils
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_philo_must_eat;
	int		must_eat;
	long	simulation_start;
	bool	threads_ready;
	t_fork	*forks;
	t_philo	*philos;
}	t_utils;

long	ft_atol(char *str);
int		ft_isdigit(char c);
void	check_initialisers(int argc, t_utils *utils, char *argv[]);
void	init_utils(int argc, t_utils *utils, char *argv[]);
void	init_philos(t_utils *util);
void	print_error(void);
void	*start_routine(void *args);

#endif