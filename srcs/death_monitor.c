/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:01:18 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/04 11:39:22 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"


static int	has_eaten_enough(t_utils *util)
{
	int	index;

	index = -1;
	while (++index < util->num_of_philo)
	{
		if (util->philos[index].meals_eaten != util->num_philo_must_eat)
			return (0);
	}
	return (1);
}

void	*death_monitor(void *args)
{
	int		index;
	t_utils	*util;

	util = (t_utils *)args;
	while (!util->simulation_has_ended)
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
				util->simulation_has_ended = true;
				pthread_mutex_unlock(&util->meal_lock);
				return (NULL);
			}
			if (has_eaten_enough(util))
				util->simulation_has_ended = true;
			pthread_mutex_unlock(&util->meal_lock);
		}
		precise_sleep(1000, util);
	}
	return (NULL);
}
