/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:45:53 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 02:34:20 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_usleep(size_t time, t_philo *philo)
{
	size_t	current;
	size_t	totall;

	current = ms_time();
	(void)philo;
	totall = current + time;
	while (1)
	{
		if (totall <= ms_time())
		{
			break ;
		}
		usleep(1000);
	}
}
