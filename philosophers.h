/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/12 18:50:00 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

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
	int	number_of_eatings;
}	t_utils;

long	ft_atol(char *str);
int		ft_isdigit(char c);
int		check_initialisers(t_utils *utils, char *argv[]);
void	print_error(void);

#endif