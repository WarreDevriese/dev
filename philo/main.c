/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:35:22 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/02 12:42:39 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_params(t_params *params, int argc, char **argv)
{
	params->number_of_philosophers = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4])
	params->number_of_times_each_philosopher_must_eat = 0; 
	if (argc == 6)
		params->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

static bool	ft_init_forks(t_params *params)
{
	int		i;

	*forks = malloc(sizeof(pthread_mutex_t) * params.number_of_philosophers);
	if (!*forks)
		return (false);
	i = -1;
	while (++i < params.number_of_philosophers)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(*forks)[i]);
			free(*forks);
			free(*philosophers);
			return (false);
		}
	}
	return (true);
}

static bool	ft_init_philosophers(t_params *params)
{
	int		i;

	*philosophers = malloc(sizeof(pthread_t) * params.number_of_philosophers);
	if (!*philosophers)
		return (false);
	i = -1;
	while (++i < params.number_of_philosophers)
	{
		if (pthread_create(&(*philosophers)[i], NULL, ft_philosopher_behavior, NULL))
		{
			free(*philosophers);
			return (false);
		}
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_params		p;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	ft_init_params(&p, argc, argv);
	if (!ft_init_philosophers(&p))
	{
		printf("System error creating threads\n");
		return (1);
	}
	if (!ft_init_forks(&p))
	{
		printf("System error creating mutexes\n");
		return (1);
	}

}
