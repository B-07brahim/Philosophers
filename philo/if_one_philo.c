/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_one_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:00:02 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 17:12:46 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	if_one_philo(t_philo *philo, int right)
{
	if (philo->info->number_of_philo == 1)
	{
		pthread_mutex_lock(&philo->info->gard_info);
		philo->info->number_eate = 0;
		pthread_mutex_unlock(&philo->info->gard_info);
		pthread_mutex_unlock(&philo->info->fork[right]);
		usleep(philo->info->time_to_die * 1000);
		print_msgg("died", philo);
		pthread_mutex_lock(&philo->info->gard_info);
		return (0);
	}
	return (1);
}
