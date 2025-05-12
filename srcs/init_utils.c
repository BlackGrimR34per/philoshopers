/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:06:44 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/12 23:10:04 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_utils(int argc, t_utils *utils, char *argv[])
{
	memset(utils, 0, sizeof(t_utils));
	utils->num_of_philo = ft_atol(argv[1]);
	utils->time_to_die = ft_atol(argv[2]);
	utils->time_to_eat = ft_atol(argv[3]);
	utils->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
	{
		utils->must_eat = 1;
		utils->num_philo_must_eat = ft_atol(argv[5]);
	}
}
