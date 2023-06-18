/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:18:21 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 17:01:58 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*staff(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep (100);
		philo->time = ms_time();
		sem_wait(philo->race);
		philo->time_die = philo->info->time_to_die + philo->start_eat;
		if ((philo->time_die <= philo->time) && philo->start_eat != 0)
			print_msgg("died", philo);
		sem_post(philo->race);
		if (philo->info->number_eate == 0)
		{
			philo->time = ((philo->info->time_eat + philo->info->time_sleep)
					/ 2) * 2;
			if ((philo->time * philo->info->count)
				<= ms_time() - philo->info->start_time)
				exit (1);
		}
	}
	return (NULL);
}
