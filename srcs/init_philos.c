/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:34:10 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/12 23:52:23 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*temp(void *args)
{
	printf("HELLO\n");
}

void	init_philos(t_utils *util)
{
	pthread_t	*threads;
	int			index;

	threads = malloc(sizeof(pthread_t) * util->num_of_philo);
	index = -1;
	while (++index < util->num_of_philo)
		pthread_create(threads + index, NULL, temp, NULL);
	index = -1;
	while (++index < util->num_of_philo)
		pthread_join(threads[index], NULL);
	index = -1;
	free(threads);
}

