/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:29:15 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:34:01 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	died(t_philo *philo, size_t time_die)
{
	size_t				current_time;
	struct timeval		time;

	gettimeofday(&time, NULL);
	current_time = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	pthread_mutex_lock(&philo->gard_philo);
	if ((time_die <= current_time) && philo->start_eating != 0)
	{
		pthread_mutex_unlock(&philo->gard_philo);
		pthread_mutex_lock(&philo->info->gard_info);
		philo->info->is_die = 1;
		philo->info->validi = 0;
		pthread_mutex_unlock(&philo->info->gard_info);
		print_msgg("died", philo);
		pthread_mutex_lock(&philo->gard_philo);
	}
	pthread_mutex_unlock(&philo->gard_philo);
}
