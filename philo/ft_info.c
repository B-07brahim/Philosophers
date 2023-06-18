/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:32:10 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:39:20 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_info(t_info *info, char **argv)
{
	struct timeval	time;

	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->is_die = 1;
	info->validi = 1;
	info->number_eate = -1;
	if (argv[5] != NULL)
	{
		info->number_eate = (ft_atoi(argv[5]) * (info->number_of_philo));
		info->validi = 1;
	}
	gettimeofday(&time, NULL);
	info->start_time = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	info->fork = ft_calloc (info->number_of_philo, sizeof(pthread_mutex_t));
	if (info->fork == NULL)
	{
		free (info);
		return (1);
	}
	return (0);
}
