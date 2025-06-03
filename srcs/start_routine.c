/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:28 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/03 17:58:08 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// Spinlock?
static void	wait_threads(t_utils *utils)
{
	while (!utils->threads_ready)
		;
}

void	print_status(t_utils *util, int id, char *message)
{
	pthread_mutex_lock(&util->print_lock);
	printf("%ld %d %s\n", get_time(MILLISECONDS) - util->simulation_start, id, message);
	pthread_mutex_unlock(&util->print_lock);
}

void	start_eating(t_utils *util, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&util->forks[philo->left_fork].fork);
		print_status(util, philo->id, "has taken left fork");

		pthread_mutex_lock(&util->forks[philo->right_fork].fork);
		print_status(util, philo->id, "has taken right fork");

		print_status(util, philo->id, "is eating");
		pthread_mutex_lock(&util->meal_lock);
		philo->last_meal = get_time(MILLISECONDS);
		pthread_mutex_unlock(&util->meal_lock);
		usleep(util->time_to_eat * 1000);
		philo->meals_eaten++;

		pthread_mutex_unlock(&util->forks[philo->left_fork].fork);
		pthread_mutex_unlock(&util->forks[philo->right_fork].fork);

		start_sleeping(util, philo);
		print_status(util, philo->id, "is thinking");
	}
	else
	{
		pthread_mutex_lock(&util->forks[philo->right_fork].fork);
		print_status(util, philo->id, "has taken right fork");

		pthread_mutex_lock(&util->forks[philo->left_fork].fork);
 		print_status(util, philo->id, "has taken left fork");

		print_status(util, philo->id, "is eating");
		philo->last_meal = get_time(MILLISECONDS);
		usleep(util->time_to_eat * 1000);
		philo->meals_eaten++;

		pthread_mutex_unlock(&util->forks[philo->right_fork].fork);
		pthread_mutex_unlock(&util->forks[philo->left_fork].fork);

		start_sleeping(util, philo);
		print_status(util, philo->id, "is thinking");
	}
}

void	start_sleeping(t_utils *util, t_philo *philo)
{
	print_status(util, philo->id, "is sleeping");
	usleep(util->time_to_sleep * 1000);
}

void	*start_routine(void *args)
{
	t_utils	*util;
	t_philo	*philo;

	philo = (t_philo *)args;
	util = philo->util;
	wait_threads(util);
	while (!util->a_philo_has_died)
		start_eating(util, philo);
	return (0);
}
