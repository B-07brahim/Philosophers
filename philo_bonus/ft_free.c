/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:00:36 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/14 19:09:42 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free(t_philo *philo, t_info *info, int i)
{
	int		status;

	while (++i < info->number_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < info->number_of_philo)
			{
				sem_close(philo[i].race);
				free(philo[i].v);
				kill(info->id_perim[i], SIGINT);
			}
			break ;
		}
	}
	sem_close(info->fork);
	sem_close(info->gard);
	sem_unlink("/fork");
	sem_unlink("/garddd");
	free (info->id_perim);
	free (info);
	free (philo);
	pthread_join(info->staff, NULL);
}
