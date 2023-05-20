/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:41:20 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 13:35:51 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static bool	ft_numbers_ok(size_t size, char **args)
{
	long	num;
	int		sign;
	char	*ptr;

	while (size--)
	{
		num = 0;
		sign = 1;
		ptr = args[size];
		if (*ptr == '-')
		{
			sign = -1;
			ptr++;
		}
		while (*ptr)
		{
			num = num * 10 + (*ptr - '0');
			if (!ft_isdigit(*ptr) || sign * num > INT_MAX || sign
				* num < INT_MIN)
				return (false);
			ptr++;
		}
	}
	return (true);
}

static int	*ft_init_int_array(size_t size, char **args)
{
	int	*int_array;

	int_array = (int *)malloc(size * sizeof(int));
	if (!int_array)
		ft_error(NULL);
	while (size--)
		int_array[size] = ft_atoi(args[size]);
	return (int_array);
}

static bool	ft_doubles_ok(size_t size, int *int_array)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (int_array[i] == int_array[j])
				return (false);
	}
	return (true);
}

t_stacks	ft_parse_args(size_t size, char **args)
{
	t_stacks	stacks;
	int			*int_array;

	if (!ft_numbers_ok(size, args))
		ft_error(NULL);
	int_array = ft_init_int_array(size, args);
	if (!ft_doubles_ok(size, int_array))
		ft_error(int_array);
	if (!ft_init_stacks(size, int_array, &stacks))
		ft_error(int_array);
	free(int_array);
	return (stacks);
}

t_stacks	ft_parse_string(char *argv)
{
	size_t		size;
	char		**args;
	t_stacks	stacks;

	size = ft_word_count(argv, ' ');
	if (size > 500)
		exit(0);
	args = ft_split(argv, ' ');
	stacks = ft_parse_args(size, args);
	ft_free_array(args, size);
	return (stacks);
}
