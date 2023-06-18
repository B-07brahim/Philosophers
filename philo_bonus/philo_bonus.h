/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:45:02 by bchifour          #+#    #+#             */
/*   Updated: 2023/03/15 16:56:41 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

// shared ressources info between philo
typedef struct s_info
{
	int			number_of_philo;
	int			time_sleep;
	int			time_to_die;
	int			time_eat;
	size_t		start_time;
	pthread_t	staff;
	int			number_eate;
	int			validi;
	int			is_die;
	int			*id_perim;
	sem_t		*fork;
	sem_t		*gard;
	int			count_race;
	int			count;
}		t_info;

// info for each philo
typedef struct s_philo
{
	int		id;
	size_t	start_eat;
	pid_t	pid;
	size_t	time;
	size_t	time_die;
	sem_t	*race;
	t_info	*info;
	char	*v;
	char	*to;
}		t_philo;

// fuction get info and  initialisation
void	ft_info(t_info *info, char **argv);
void	ft_check_arg(char **argv);
void	ft_init(t_philo *philo, t_info *info, int i);

//fuction philosphers meal
void	philosophers(t_philo *philo);
void	*staff(void *arg);
void	if_one_philo(t_philo *philo);
void	init_each_philo(t_philo *philo);

// fuction utils
void	print_msg(char *str, t_philo *philo);
void	print_msgg(char *str, t_philo *philo);
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
size_t	ms_time(void);
void	my_usleep(size_t time, t_philo *philo);
void	failed(t_info *info, int i, int count, t_philo *philo);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

// free ressources
void	ft_free(t_philo *philo, t_info *info, int i);

#endif