/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:57:57 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 21:34:43 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stacks(t_stacks *stacks)
{
	if (stacks->a)
	{
		if (stacks->a->array)
			free(stacks->a->array);
		free(stacks->a);
	}
	if (stacks->b)
	{
		if (stacks->b->array)
			free(stacks->b->array);
		free(stacks->b);
	}
}

static void	ft_init_normalized_stack(size_t size, int *int_array,
		t_stacks *stacks)
{
	t_normalizing_params	p;

	p.j = -1;
	while (++p.j < size)
		if (int_array[p.j] == INT_MAX)
			p.int_max_flag = p.j;
	p.i = -1;
	while (++p.i < size)
	{
		p.j = -1;
		p.min_value = INT_MAX;
		while (++p.j < size)
		{
			if (int_array[p.j] < p.min_value ||
				(p.i == size - 1 && p.j == p.int_max_flag))
			{
				p.min_pos = p.j;
				p.min_value = int_array[p.j];
			}
		}
		stacks->a->array[p.min_pos] = (short)p.i;
		int_array[p.min_pos] = INT_MAX;
	}
}

static void	ft_init_empty_stack(size_t size, t_stacks *stacks)
{
	while (size--)
		stacks->b->array[size] = -1;
}

int	ft_init_stacks(size_t size, int *int_array, t_stacks *stacks)
{
	stacks->a = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->a)
		return (0);
	stacks->b = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->b)
		return (0);
	stacks->a->array = (short *)malloc(size * sizeof(short));
	if (!stacks->a->array)
		return (0);
	ft_init_normalized_stack(size, int_array, stacks);
	stacks->b->array = (short *)malloc(size * sizeof(short));
	if (!stacks->b->array)
		return (0);
	ft_init_empty_stack(size, stacks);
	stacks->a->size = size;
	stacks->b->size = 0;
	return (1);
}
