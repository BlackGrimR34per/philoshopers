/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:27:23 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/03 17:45:28 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	precise_sleep(long usec, t_utils *util)
{
	long	start;
	long	elapsed;
	long	remainder;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < usec)
	{
		if (util->simulation_has_ended)
			break ;
		elapsed = get_time(MICROSECONDS) - start;
		remainder = usec - elapsed;
		if (remainder > 1e3)
			usleep(remainder / 2);
		else
		{
			while (get_time(MICROSECONDS) - start < usec)
				;
		}
	}
}
