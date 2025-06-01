/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:55:31 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/01 19:07:10 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_utils(t_utils *util)
{
	int	index;

	index = -1;
	while (++index < util->num_of_philo)
		pthread_mutex_destroy(&util->forks[index].fork);
	free(util->philos);
	free(util->forks);
}
