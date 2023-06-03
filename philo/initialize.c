/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warredevriese <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:42:14 by warredevriese     #+#    #+#             */
/*   Updated: 2023/06/03 21:55:11 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

bool	ft_init_params(t_params *p, int argc, char **argv)
{
	p->number_of_philosophers = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->number_of_times_each_philosopher_must_eat = 0; 
	if (argc == 6)
		p->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	p->is_alive = true;
	p->death_flag = malloc(sizeof(bool));
	if (!p->death_flag)
		return (false);
	*p->death_flag = false;
	return (true);
}

bool	ft_init_forks(t_params  *p)
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

bool ft_init_philosophers(t_params *p)
{
	t_params	*p_array;	
	int			i;

	p->philosophers = malloc(sizeof(pthread_t) * p->number_of_philosophers);
	p_array = malloc(sizeof(t_params) * p->number_of_philosophers);
	if (!p->philosophers || !p_array)
		return (false);
	i = -1;
	while (++i < p->number_of_philosophers)
	{
		p_array[i] = *p;
		p_array[i].philosopher_number = i;
		if (pthread_create(&p->philosophers[p->philosopher_number], NULL, ft_philosopher_behavior, &p_array[i]))
			return (false);
	}
	return (true);
}
