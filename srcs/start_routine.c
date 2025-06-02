/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:28 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/02 11:50:05 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// Spinlock?
static void	wait_threads(t_utils *utils)
{
	while (!utils->threads_ready)
		;
}

static void	start_eating(t_utils *util, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&util->forks[philo->left_fork].fork);
		printf("Philo %d acquired left fork %d\n", philo->id, philo->left_fork);
		pthread_mutex_lock(&util->forks[philo->right_fork].fork);
		printf("Philo %d acquired right fork %d\n", philo->id, philo->right_fork);
		pthread_mutex_unlock(&util->forks[philo->left_fork].fork);
		pthread_mutex_unlock(&util->forks[philo->right_fork].fork);
		printf("Philo %d has finished eating %d\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(&util->forks[philo->right_fork].fork);
		printf("Philo %d acquired right fork %d\n", philo->id, philo->right_fork);
		pthread_mutex_lock(&util->forks[philo->left_fork].fork);
 		printf("Philo %d acquired left fork %d\n", philo->id, philo->left_fork);
		pthread_mutex_unlock(&util->forks[philo->right_fork].fork);
		pthread_mutex_unlock(&util->forks[philo->left_fork].fork);
	}
}

void	start_sleeping(t_utils *util, t_philo *philo)
{
	usleep(util->time_to_sleep);
}

void	*start_routine(void *args)
{
	t_utils	*util;
	t_philo	*philo;

	philo = (t_philo *)args;
	util = philo->util;
	wait_threads(util);
	start_eating(util, philo);
	return (0);
}
