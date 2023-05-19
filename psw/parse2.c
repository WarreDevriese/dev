/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:57:57 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 15:01:15 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numbers_ok(size_t size, char **args)
{
	long	num;
	int		sign;
	while (size--)
	{
		num = 0;
		sign = 1;
		if (*args[size] == '-')
		{
			sign = -1;
			args[size]++;
		}
		while (*args[size])
		{
			if (!ft_isdigit(*args[size]))
				return (0);
			num = num * 10 + (*args[size] - '0');
			if (sign * num > INT_MAX || sign * num < INT_MIN)
				return (0);
			args[size]++;
		}
	}
	return (1);
}

int	ft_doubles_ok(size_t size, int *int_array)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (int_array[i] == int_array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
