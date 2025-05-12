/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/12 23:50:31 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>


// typedef struct s_philo
// {
// 	struct timeval tv;

// }	t_philo;

typedef struct s_utils
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_philo_must_eat;
	int	must_eat;
}	t_utils;

long	ft_atol(char *str);
int		ft_isdigit(char c);
void	check_initialisers(int argc, t_utils *utils, char *argv[]);
void	init_utils(int argc, t_utils *utils, char *argv[]);
void	init_philos(t_utils *util);
void	print_error(void);

#endif