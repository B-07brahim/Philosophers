/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:41:10 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:48:54 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

// shared ressources info between philo
typedef struct s_info
{
	int				number_of_philo;
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	size_t			start_time;
	int				number_eate;
	int				validi;
	int				is_die;
	pthread_mutex_t	*fork;
	pthread_mutex_t	gard_info;
}		t_info;

// info for each philo 
typedef struct s_philo
{
	int				id;
	int				left;
	size_t			start_eating;
	pthread_t		t;
	pthread_t		s;
	pthread_mutex_t	gard_philo;
	t_info			*info;
}		t_philo;

//  fuction get info and  initialisation
int		ft_info(t_info *info, char **argv);
int		ft_check_arg(char **argv);
int		ft_init(t_philo *philo, t_info *info, int i);

//fuction philosphers meal
void	*philos(t_philo	*philo);
int		if_one_philo(t_philo *philo, int right);
void	*staff(t_philo *philo);
int		creat_philo(t_philo *philo, t_info *info, int i);
void	died(t_philo *philo, size_t time_die);

// fuction utils
void	print_msg(char *str, t_philo *philo);
void	print_msgg(char *str, t_philo *philo);
void	update_time(t_philo *philo);
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
void	my_usleep(size_t time, t_philo *philo);
size_t	ms_time(void);

// free ressources
void	ft_free(t_philo *philo, t_info *info, int philo_number);

#endif