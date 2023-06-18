/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:26:53 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 02:32:35 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(char *str, t_philo *philo)
{
	struct timeval	time;
	size_t			timee;
	size_t			current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_lock(&philo->info->gard_info);
	timee = current_time - philo->info->start_time;
	if (!philo->info->is_die && !(philo->info->number_eate == 0))
		printf("%zu  %d %s\n", timee, philo->id + 1, str);
	pthread_mutex_unlock(&philo->info->gard_info);
}

void	print_msgg(char *str, t_philo *philo)
{
	struct timeval	time;
	size_t			timee;
	size_t			current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_lock(&philo->info->gard_info);
	timee = current_time - philo->info->start_time;
	pthread_mutex_unlock(&philo->info->gard_info);
	printf("%zu  %d %s\n", timee, philo->id + 1, str);
}
