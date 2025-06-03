/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:34:10 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/03 18:00:35 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// long	get_time()
// {
// 	struct timeval	tv;
// 	long			milliseconds;

// 	gettimeofday(&tv, NULL);
// 	milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
// 	return (milliseconds);
// }

long	get_time(t_time_measurement time_measurement)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		exit();
	else if (time_measurement == MICROSECONDS)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else if (time_measurement == MILLISECONDS)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (time_measurement == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
}

// f-sanitize=threads complains, change the function to be more modular
void	init_philos(t_utils *util)
{
	int			index;
	pthread_t	monitoring_thread;

	util->philos = malloc(sizeof(t_philo) * util->num_of_philo);
	util->forks = malloc(sizeof(t_fork) * util->num_of_philo);
	index = -1;
	while (++index < util->num_of_philo)
	{
		util->forks[index].id = index;
		pthread_mutex_init(&util->forks[index].fork, NULL);
	}
	index = -1;
	while (++index < util->num_of_philo)
	{
		util->philos[index].id = index + 1;
		util->philos[index].is_alive = true;
		util->philos[index].meals_eaten = 0;
		util->philos[index].last_meal = 0;
		util->philos[index].util = util;
		util->philos[index].left_fork = index;
		util->philos[index].right_fork = (index + 1) % util->num_of_philo;
		pthread_create(&util->philos[index].thread, NULL,
			start_routine, &util->philos[index]);
	}
	util->simulation_start = get_time(MILLISECONDS);
	util->threads_ready = true;

	pthread_create(&monitoring_thread, NULL, death_monitor, util);

	index = -1;
	while (++index < util->num_of_philo)
		pthread_join(util->philos[index].thread, NULL);

	pthread_join(monitoring_thread, NULL);
}
