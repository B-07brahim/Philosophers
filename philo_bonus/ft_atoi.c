/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:44:46 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/03 10:55:30 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	nb;

	nb = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (ft_isdigit(*str) == 0)
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - 48);
		if (nb > 2147483647)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (nb);
}
