/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:28 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/01 19:52:38 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// Spinlock?
static void	wait_threads(t_utils *utils)
{
	while (!utils->threads_ready)
		;
}

// static void	start_eating(t_utils *utils)
// {
	
// }

void	*start_routine(void *args)
{
	t_utils	*util;
	t_philo	*philo;

	philo = (t_philo *)args;
	util = philo->util;
	wait_threads(util);
	// start_eating(&util);
	return (0);
}
