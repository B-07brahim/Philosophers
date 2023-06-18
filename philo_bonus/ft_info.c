/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 06:42:33 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/11 22:21:53 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_info(t_info *info, char **argv)
{
	ft_check_arg(argv);
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->is_die = 1;
	info->validi = 1;
	info->number_eate = -1;
	if (argv[5] != NULL)
	{
		info->number_eate = (ft_atoi(argv[5]));
		info->count = (ft_atoi(argv[5]));
		info->validi = 1;
	}
	info->start_time = ms_time();
	info->id_perim = ft_calloc (info->number_of_philo, sizeof(int));
	info->count_race = 0;
	if (info->id_perim == NULL)
	{
		free (info);
		exit (1);
	}
}
