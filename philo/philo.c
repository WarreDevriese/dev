/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warredevriese <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:40:09 by warredevriese     #+#    #+#             */
/*   Updated: 2023/06/02 17:35:30 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_params(t_params *p, int argc, char **argv)
{
	p->number_of_philosophers = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->number_of_times_each_philosopher_must_eat = 0; 
	if (argc == 6)
		p->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

static bool	ft_init_forks(t_params  *p)
{
	p->forks = malloc(sizeof(pthread_mutex_t) * p->number_of_philosophers);
	if (!p->forks)
		return (false);
	p->fork_number = -1;
	while (++p->fork_number < p->number_of_philosophers)
		if (pthread_mutex_init(&p->forks[p->fork_number], NULL))
			return (false);
	return (true);
}

static bool ft_init_philosophers(t_params *p)
{
	p->philosophers = malloc(sizeof(pthread_t) * p->number_of_philosophers);
	if (!p->philosophers)
		return (false);
	p->philosopher_number = -1;
	while (++p->philosopher_number < p->number_of_philosophers)
		if (pthread_create(&p->philosophers[p->philosopher_number], NULL, ft_philosopher_behavior, p))
			return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_params	p;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	ft_init_params(&p, argc, argv);	
	if (!ft_init_forks(&p) || !ft_init_philosophers(&p))
	{
		ft_cleanup(&p);
		return (1);
	}
	ft_cleanup(&p);
	return (0);
}
