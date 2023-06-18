/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:05:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:38:10 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	creat_philo(t_philo *philo, t_info *info, int i)
{
	while (++i < info->number_of_philo)
	{
		philo[i].id = i;
		philo[i].info = info;
		pthread_mutex_lock(&info->gard_info);
		philo[i].info->is_die = 0;
		pthread_mutex_unlock(&info->gard_info);
		if (pthread_create(&philo[i].t, NULL, (void *)philos, &philo[i]) != 0)
		{
			ft_free(philo, info, info->number_of_philo);
			return (1);
		}
		if (pthread_create(&philo[i].s, NULL, (void *)staff, &philo[i]) != 0)
		{
			ft_free(philo, info, info->number_of_philo);
			return (1);
		}
		if (pthread_detach(philo[i].s) != 0)
		{
			ft_free(philo, info, info->number_of_philo);
			return (1);
		}
		usleep(100);
	}
	return (0);
}
