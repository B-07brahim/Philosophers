/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:30:08 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/08 20:20:32 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	n;

	n = size * count;
	p = malloc(n);
	if (p == NULL)
		return (NULL);
	while (n--)
		*(p + n) = 0;
	return (p);
}
