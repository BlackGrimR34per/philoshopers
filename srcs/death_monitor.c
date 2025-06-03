/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:01:18 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/03 17:56:59 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*death_monitor(void *args)
{
	int		index;
	t_utils	*util;

	util = (t_utils *)args;
	while (!util->a_philo_has_died)
	{
		index = -1;
		while (++index < util->num_of_philo)
		{
			if (util->philos[index].last_meal == 0)
				break;
			pthread_mutex_lock(&util->meal_lock);
			if (get_time(MILLISECONDS) - util->philos[index].last_meal > util->time_to_die)
			{
				print_status(util, util->philos->id, "has died");
				util->a_philo_has_died = true;
				pthread_mutex_unlock(&util->meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&util->meal_lock);
		}
		usleep(100);
	}
	return (NULL);
}
