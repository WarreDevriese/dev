/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:24:26 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/03 12:59:59 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long ft_max(long long a, long long b)
{
    if (a >= b)
        return a;
    else
        return b;
}

long long ft_min(long long a, long long b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	if (!nptr)
		return (0);
	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * result);
}
