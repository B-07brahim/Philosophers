/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:33:03 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/14 19:01:52 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_msg(char *str, t_philo *philo)
{
	size_t			timee;
	size_t			current_time;

	current_time = ms_time();
	timee = current_time - philo->info->start_time;
	sem_wait(philo->info->gard);
	printf("%zu  %d %s\n", timee, philo->id + 1, str);
	sem_post(philo->info->gard);
}

void	print_msgg(char *str, t_philo *philo)
{
	size_t			timee;
	size_t			current_time;

	current_time = ms_time();
	timee = current_time - philo->info->start_time;
	sem_wait(philo->info->gard);
	printf("%zu  %d %s\n", timee, philo->id + 1, str);
	free(philo[philo->id].v);
	sem_close(philo[philo->id].race);
	exit (1);
}
