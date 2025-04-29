/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_initialisers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:26:52 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/29 18:35:11 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_initialisers(char *argv[])
{
	if (check_philo_num(argv[1]))
		return (1);
	if (check_die_time(argv[2]))
		return (1);
}
