/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:28 by yosherau          #+#    #+#             */
/*   Updated: 2025/05/14 18:05:57 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// Spinlock?
static void	wait_threads(t_utils *utils)
{
	while (!utils->threads_ready)
		;
}

void	*start_routine(void *args)
{
	t_utils	*utils;

	utils = (t_utils *)args;
	wait_threads(utils);
}
