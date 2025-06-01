/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:28 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/01 18:50:20 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// Spinlock?
// static void	wait_threads(t_utils *utils)
// {
// 	while (!utils->threads_ready)
// 		;
// }

void	*start_routine(void *args)
{
	t_utils	*utils;

	(void)args;
	(void)utils;
	printf("Hello\n");
	return (0);
}
