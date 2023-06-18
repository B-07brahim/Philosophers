/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:01:02 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:40:18 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_arg(char **argv)
{
	int	i;

	i = 0;
	if (ft_atoi(argv[1]) == -1)
		i++;
	if (ft_atoi(argv[2]) == -1)
		i++;
	if (ft_atoi(argv[3]) == -1)
		i++;
	if (ft_atoi(argv[4]) == -1)
		i++;
	if (argv[5] != NULL)
	{
		if (ft_atoi(argv[5]) == -1)
			i++;
	}
	if (i != 0)
	{
		write(2, "Error: only positive int are allowed\n", 37);
		return (1);
	}
	return (0);
}
