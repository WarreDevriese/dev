/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:10:19 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/03 21:37:49 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	ft_get_current_time()
{

	 struct	timeval tv;
	 gettimeofday(&tv, NULL);
	 return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

static void	ft_print_status(t_params *p, const char *status)
{
	 printf("%lld %d %s\n", ft_get_current_time(), p->philosopher_number + 1, status);
}

static void	ft_monitor_life(void *arg)
{
	t_params	*p;

	p = (t_params *)arg;
	while (p->is_alive)
	{
		if ()
		{
			p->is_alive = false;
			ft_print_status(p, "died");
		}
	}

}

void	ft_philosopher_behavior(void *arg)
{
	t_params	*p;
	pthread_t	monitor_thread;
	int	first_fork;
	int	second_fork;

	p = (t_params *)arg;

	if (pthread_create(&monitor_thread, NULL, ft_monitor_life, p))
		return ;

	first_fork = ft_min(p->philosopher_number, (p->philosopher_number + 1) % p->number_of_philosophers);
	second_fork = ft_max(p->philosopher_number, (p->philosopher_number + 1) % p->number_of_philosophers);


	while (1)
	{
		ft_print_status(p, "is thinking");
		
		pthread_mutex_lock(&p->forks[first_fork]);
		ft_print_status(p, "has taken a fork");
		pthread_mutex_lock(&p->forks[second_fork]);
		ft_print_status(p, "has taken a fork");

		ft_print_status(p, "is eating");
		usleep(p->time_to_eat * 1000);
		p->last_meal = ft_get_current_time();

		pthread_mutex_unlock(&p->forks[first_fork]);
		pthread_mutex_unlock(&p->forks[second_fork]);

		ft_print_status(p, "is sleeping");
		usleep(p->time_to_sleep * 1000);
	}

	if (pthread_join(monitor_thread, NULL))
		return ;
}
