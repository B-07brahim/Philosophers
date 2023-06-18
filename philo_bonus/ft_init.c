/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 06:46:13 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/14 19:03:17 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init(t_philo *philo, t_info *info, int i)
{
	i = info->number_of_philo;
	sem_unlink("/fork");
	sem_unlink("/garddd");
	info->gard = sem_open("/garddd", O_CREAT | O_EXCL, 0644, 1);
	if (info->gard == SEM_FAILED)
		failed(info, 1, 0, philo);
	info->fork = sem_open("/fork", O_CREAT | O_EXCL, 0644, i);
	if (info->fork == SEM_FAILED)
		failed(info, 2, 0, philo);
	i = -1;
	while (++i < info->number_of_philo)
	{
		philo[i].info = info;
		philo[i].info->is_die = 0;
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			philo[i].id = i;
			philosophers(&philo[i]);
		}
		if (philo[i].pid == -1)
			failed(info, 3, i, philo);
		info->id_perim[i] = philo[i].pid;
		usleep (100);
	}
}
