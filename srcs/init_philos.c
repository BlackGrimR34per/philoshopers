/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:34:10 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/01 19:48:37 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static long	get_time()
{
	struct timeval	tv;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (milliseconds);
}

// f-sanitize=threads complains, change the function to be more modular
void	init_philos(t_utils *util)
{
	int	index;

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
		util->philos[index].util = util;
		util->philos[index].left_fork = index;
		util->philos[index].right_fork = (index + 1) % util->num_of_philo;
		pthread_create(&util->philos[index].thread, NULL,
			start_routine, &util->philos[index]);
	}
	util->simulation_start = get_time();
	util->threads_ready = 1;
	index = -1;
	while (++index < util->num_of_philo)
		pthread_join(util->philos[index].thread, NULL);
}
