/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:36:06 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/03 08:52:19 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

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
}				t_params;

int		ft_atoi(const char *nptr);
void	ft_init_params(t_params *p, int argc, char **argv);
bool	ft_init_forks(t_params  *p);
bool ft_init_philosophers(t_params *p);

#endif
