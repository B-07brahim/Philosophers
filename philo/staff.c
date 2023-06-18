/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:30:41 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:33:29 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*staff(t_philo *philo)
{
	size_t				time_die;

	pthread_mutex_lock(&philo->info->gard_info);
	while (!philo->info->is_die)
	{
		pthread_mutex_lock(&philo->gard_philo);
		time_die = philo->info->time_to_die + philo->start_eating;
		pthread_mutex_unlock(&philo->gard_philo);
		pthread_mutex_unlock(&philo->info->gard_info);
		died(philo, time_die);
		if (philo->info->number_eate == 0)
		{
			pthread_mutex_lock(&philo->info->gard_info);
			philo->info->is_die = 1;
			philo->info->validi = 0;
			pthread_mutex_unlock(&philo->info->gard_info);
		}
		usleep(100);
		pthread_mutex_lock(&philo->info->gard_info);
	}
	pthread_mutex_unlock(&philo->info->gard_info);
	return (NULL);
}
