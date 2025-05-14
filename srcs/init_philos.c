/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:34:10 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/14 20:05:36 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	
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
		util->philos[index].left_fork = index;
		util->philos[index].right_fork = (index + 1) % util->num_of_philo;
		pthread_create(&util->philos[index].thread, NULL,
			start_routine, util);
	}
	util->simulation_start = gettimeofday();
	util->threads_ready = 1;
	index = -1;
	while (++index < util->num_of_philo)
		pthread_join(util->philos[index].thread, NULL);
}
