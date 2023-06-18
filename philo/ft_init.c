/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:45:25 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:38:02 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init(t_philo *philo, t_info *info, int i)
{
	int	_r;

	i = -1;
	while (++i < info->number_of_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
		{
			ft_free(philo, info, i);
			return (1);
		}
	}
	pthread_mutex_init(&info->gard_info, NULL);
	pthread_mutex_init(&philo->gard_philo, NULL);
	creat_philo(philo, info, -1);
	i = -1;
	while (++i < info->number_of_philo)
	{
		_r = pthread_join(philo[i].t, NULL);
		if (_r != 0)
		{
			ft_free(philo, info, info->number_of_philo);
			return (1);
		}
	}
	return (0);
}
