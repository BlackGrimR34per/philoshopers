/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_initialisers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:26:52 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/13 19:38:12 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// Might need to change the checks
void	check_initialisers(int argc, t_utils *utils, char *argv[])
{
	init_utils(argc, utils, argv);
	if (utils->num_of_philo < 1 || utils->num_of_philo > 200)
		exit(1);
	if (utils->time_to_die < 60)
		exit(1);
	if (utils->time_to_eat < 60)
		exit(1);
	if (utils->time_to_sleep < 60)
		exit(1);
	if (utils->must_eat)
		if (utils->num_philo_must_eat == 0)
			exit(1);
}
