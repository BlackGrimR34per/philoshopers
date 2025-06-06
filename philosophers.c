/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:28:47 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/03 02:45:30 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

int	main(int argc, char *argv[])
{
	t_utils	util;

	if (argc != 5 && argc != 6)
		return (print_error(INVALID_ARGS));
	check_initialisers(argc, &util, argv);
	init_philos(&util);
	free_utils(&util);
}
