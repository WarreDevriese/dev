/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:41:20 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 15:06:07 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_initialize_int_array(size_t size, char **args)
{
	int		*int_array;

	int_array = (int *)malloc(size * sizeof(int));
	if (!int_array)
		ft_error();
	while (size--)
		int_array[size] = ft_atoi(args[size]);
	return (int_array);
}

static void	ft_normalize_int_array(size_t size, int *int_array, t_stacks *stacks)
{
	t_normalizing_params	p;
	p.j = -1;
	while (++p.j < size)
		if (int_array[p.j] == INT_MAX)
			stacks->A->array[p.j] = (short)(size - 1);
	p.i = -1;
	while (++p.i < size)
	{
		p.j = -1;
		p.min_value = INT_MAX;
		while (++p.j < size)
		{
			if (int_array[p.j] < p.min_value)
			{
				p.min_pos = p.j;
				p.min_value = int_array[p.j];
			}
		}
		stacks->A->array[p.min_pos] = (short)p.i;
		int_array[p.min_pos] = INT_MAX;
	}
}

static int	ft_initialize_stacks(size_t size, int *int_array, t_stacks *stacks)
{
	stacks->A->array = (short *)malloc(size * sizeof(short));
	if (!stacks->A->array)
		return (0);
	ft_normalize_int_array(size, int_array, stacks);
	stacks->B->array = (short *)malloc(size * sizeof(short));
	if (!stacks->B->array)
		return (0);
	stacks->A->size = size;
	stacks->B->size = 0;
	return (1);
}

t_stacks	ft_parse_args(size_t size, char **args)
{
	t_stacks	stacks;
	int		*int_array;

	if (!ft_numbers_ok(size, args))
		ft_error();
	int_array = ft_initialize_int_array(size, args);
	if (!ft_doubles_ok(size, int_array))
	{
		free(int_array);
		ft_error();
	}
	if (!ft_initialize_stacks(size, int_array, &stacks))
	{
		free(int_array);
		ft_error();
	}
	free(int_array);
	return (stacks);
}

t_stacks	ft_parse_string(char *argv)
{
	size_t		size;
	char	**args;
	t_stacks	stacks;

	size = ft_word_count(argv, ' ');
	if (size < 2 || size > 500)
		exit(0);
	args = ft_split(argv, ' ');
	stacks = ft_parse_args(size, args);
	ft_free_array(args, size);
	return (stacks);
}
