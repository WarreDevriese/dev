/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warredevriese <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:40:09 by warredevriese     #+#    #+#             */
/*   Updated: 2023/06/03 22:17:58 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_cleanup(t_params *p)
{
	//FINISH UP
	if (p->philosophers)
		free(p->philosophers);
	if (p->forks)
		free(p->forks);
	while (p->fork_number--)
}

int	main(int argc, char **argv)
{
	t_params	p;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (!ft_init_params(&p, argc, argv) || !ft_init_forks(&p) || !ft_init_philosophers(&p))
	{
		ft_cleanup(&p);
		return (1);
	}
	ft_cleanup(&p);
	return (0);
}
