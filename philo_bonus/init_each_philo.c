/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:53:40 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/14 19:04:10 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_each_philo(t_philo *philo)
{
	int	i;

	philo->v = "/semaphor";
	philo->to = ft_itoa(philo->id);
	philo->v = ft_strjoin(philo->v, philo->to);
	sem_unlink(philo->v);
	philo->race = sem_open(philo->v, O_CREAT | O_EXCL, 0644, 1);
	if (philo->race == SEM_FAILED)
		failed(philo->info, 3, philo->info->number_of_philo, philo);
	i = pthread_create(&philo->info->staff, NULL, (void *)staff, philo);
	if (i != 0)
		failed(philo->info, 3, philo->info->number_of_philo, philo);
}
