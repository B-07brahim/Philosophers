/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:17:22 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:17:30 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_philo *philo, t_info *info, int philo_number)
{
	int	i;

	i = 0;
	while (i < philo_number)
	{
		if (pthread_mutex_destroy(&info->fork[i]) != 0)
		{
			free (info->fork);
			free (info);
			free (philo);
			return ;
		}
		i++;
	}
	pthread_mutex_destroy(&info->gard_info);
	pthread_mutex_destroy(&philo->gard_philo);
	free (info->fork);
	free (info);
	free (philo);
}
