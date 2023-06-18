/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_one_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:09:13 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/14 19:05:10 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	if_one_philo(t_philo *philo)
{
	if (philo->info->number_of_philo == 1)
	{
		philo->info->number_of_philo = 0;
		sem_post(philo->info->fork);
		usleep (philo->info->time_to_die * 1000);
		print_msg("died", philo);
		free(philo[philo->id].v);
		sem_close(philo[philo->id].race);
		exit (1);
	}
}
