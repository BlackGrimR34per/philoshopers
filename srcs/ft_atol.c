/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:31:16 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/01 18:49:42 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static void	check_input(char *str)
{
	int	len;

	len = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			exit(1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		len++;
		str++;
	}
	if (*str || len > 10 || len == 0)
		exit(1);
}

// Change magic numbers
long	ft_atol(char *str)
{
	long	nbr;

	check_input(str);
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
		nbr = nbr * 10 + (*str++ - 48);
	if (nbr > INT_MAX)
		exit(1);
	return (nbr);
}
