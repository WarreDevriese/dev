/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:36:06 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/03 13:45:37 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define _BSD_SOURCE
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

struct	s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}				t_timeval;

typedef struct	s_params
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
	int	philosopher_number;
	int	fork_number;
	long long	last_meal;
	bool	is_alive;
}				t_params;

int		ft_atoi(const char *nptr);
void	ft_init_params(t_params *p, int argc, char **argv);
bool	ft_init_forks(t_params  *p);
bool	 ft_init_philosophers(t_params *p);
long long ft_max(long long a, long long b);
long long ft_min(long long a, long long b);
void	ft_philosopher_behavior(void *arg);

#endif
