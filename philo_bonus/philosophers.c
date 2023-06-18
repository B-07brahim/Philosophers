/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:07:08 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:56:10 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philosophers(t_philo *philo)
{
	init_each_philo(philo);
	while (1)
	{
		print_msg("is thinking", philo);
		sem_wait(philo->info->fork);
		print_msg("has taken a fork", philo);
		if_one_philo(philo);
		sem_wait(philo->info->fork);
		print_msg("has taken a fork", philo);
		print_msg("is eating", philo);
		sem_wait(philo->race);
		philo->start_eat = ms_time();
		sem_post(philo->race);
		if (philo->info->number_eate > 0)
			philo->info->number_eate -= 1;
		my_usleep(philo->info->time_eat, philo);
		print_msg("is sleeping", philo);
		sem_post(philo->info->fork);
		sem_post(philo->info->fork);
		my_usleep(philo->info->time_sleep, philo);
	}
}
