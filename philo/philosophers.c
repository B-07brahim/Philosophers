/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:13:57 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 17:09:13 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philos(t_philo	*philo)
{
	pthread_mutex_lock(&philo->info->gard_info);
	while (!philo->info->is_die && philo->info->validi != 0)
	{
		pthread_mutex_unlock(&philo->info->gard_info);
		philo->left = (philo->id + 1) % philo->info->number_of_philo;
		print_msg("is thinking", philo);
		pthread_mutex_lock(&philo->info->fork[philo->id]);
		print_msg("has taken a fork", philo);
		if (if_one_philo(philo, philo->id) == 0)
			break ;
		pthread_mutex_lock(&philo->info->fork[philo->left]);
		print_msg("has taken a fork", philo);
		print_msg("is eating", philo);
		update_time(philo);
		if (philo->info->number_eate > 0)
			philo->info->number_eate -= 1;
		my_usleep(philo->info->time_to_eat, philo);
		print_msg("is sleeping", philo);
		pthread_mutex_unlock(&philo->info->fork[philo->id]);
		pthread_mutex_unlock(&philo->info->fork[philo->left]);
		my_usleep(philo->info->time_to_sleep, philo);
		pthread_mutex_lock(&philo->info->gard_info);
	}
	pthread_mutex_unlock(&philo->info->gard_info);
	return (NULL);
}
