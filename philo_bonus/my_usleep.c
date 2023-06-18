/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:45:53 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/10 16:38:39 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	my_usleep(size_t time, t_philo *philo)
{
	size_t	current;
	size_t	totall;

	current = ms_time();
	totall = current + time;
	while ((!philo->info->is_die && philo->info->validi != 0))
	{
		if (totall <= ms_time())
			break ;
		usleep(1000);
	}
}
