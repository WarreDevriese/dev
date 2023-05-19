/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:57:57 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 16:51:34 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numbers_ok(size_t size, char **args)
{
	long	num;
	int		sign;
	char	*ptr;

	while (size--)
	{
		num = 0;
		sign = 1;
		ptr = args[size];
		if (*args[size] == '-')
		{
			sign = -1;
			ptr++;
		}
		while (*ptr)
		{
			num = num * 10 + (*ptr - '0');
			if (!ft_isdigit(*ptr) || sign * num > INT_MAX || sign * num < INT_MIN)
				return (0);
			ptr++;
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
