/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 06:31:04 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/14 19:09:26 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info			*info;
	t_philo			*philo;

	if (argc == 5 || argc == 6)
	{
		info = ft_calloc (1, sizeof(*info));
		if (info == NULL)
			return (1);
		ft_info(info, argv);
		philo = ft_calloc (info->number_of_philo, sizeof(*philo));
		if (philo == NULL)
		{
			free (info->id_perim);
			free (info);
			return (1);
		}
		ft_init(philo, info, -1);
		ft_free(philo, info, -1);
	}
	else
		write(2, "number of args is wrong\n", 24);
	return (0);
}
