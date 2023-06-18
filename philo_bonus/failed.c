/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:51:31 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/10 16:24:55 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	failed(t_info *info, int i, int count, t_philo *philo)
{
	int	x;

	x = -1;
	if (i == 3)
	{
		sem_close(info->fork);
		sem_unlink("/fork");
		while (++x < count)
			kill(info->id_perim[i], SIGINT);
		i --;
	}
	if (i == 2)
	{
		sem_close(info->gard);
		sem_unlink("/garddd");
		i--;
	}
	if (i == 1)
	{
		free (info->id_perim);
		free (info);
		free (philo);
	}
	exit (1);
}
