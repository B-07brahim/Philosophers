/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:44:46 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/03 06:09:44 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	nb;
	int		min;

	nb = 0;
	min = 1;
	while (*str == ' ')
		str++;
	if (*str == '+')
	{
		str++;
		min = 1;
	}
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
	nb *= min;
	return (nb);
}
