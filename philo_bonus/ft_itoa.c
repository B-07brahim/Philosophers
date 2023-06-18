/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:13:12 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 01:23:17 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*re(int n, int i, char *new)
{
	long	nb;

	i = i - 1;
	if (n < 0)
		new[0] = '-';
	nb = n;
	while (nb)
	{
		if (nb < 0)
			nb = -nb;
		new[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n == 0)
	{
		new[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (new);
}

char	*ft_itoa(int n)
{
	long	i;
	char	*new;
	long	nb;

	i = 0;
	nb = n;
	while (nb != 0)
	{
		if (nb < 0)
		{
			i = i + 1;
			nb = -nb;
		}
		nb = nb / 10;
		i++;
	}
	if (n == 0)
		i = 1;
	new = (char *)ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	new = re(n, i, new);
	return (new);
}
