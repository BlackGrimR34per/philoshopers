/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:29:22 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/29 18:30:11 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_philo_num(int number_of_philoshophers)
{
	if (number_of_philoshophers < 0 || number_of_philoshophers > 200)
		return (1);
	return (0);
}
