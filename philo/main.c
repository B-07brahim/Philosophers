/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:17:55 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 17:14:41 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		info = ft_calloc (1, sizeof(*info));
		if (info == NULL)
			return (1);
		if (ft_check_arg(argv) != 0)
			return (1);
		if (ft_info(info, argv) != 0)
			return (1);
		philo = ft_calloc (info->number_of_philo, sizeof(*philo));
		if (philo == NULL)
		{
			free (info->fork);
			free (info);
			return (1);
		}
		if (ft_init(philo, info, -1) != 0)
			return (1);
		ft_free(philo, info, info->number_of_philo);
	}
	(!(argc == 5 || argc == 6)) && write(2, "number of args is wrong\n", 24);
	return (0);
}
