/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:57:57 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 18:38:54 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_normalized_stack_A(size_t size, int *int_array, t_stacks *stacks)
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

static void	ft_init_empty_stack_B(size_t size, t_stacks *stacks)
{
	while (size--)
		stacks->B->array[size] = -1;
}

int	ft_init_stacks(size_t size, int *int_array, t_stacks *stacks)
{
	stacks->A = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->A)
		return (0);
	stacks->B = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->B)
		return (0);
	stacks->A->array = (short *)malloc(size * sizeof(short));
	if (!stacks->A->array)
		return (0);
	ft_init_normalized_stack_A(size, int_array, stacks);
	stacks->B->array = (short *)malloc(size * sizeof(short));
	if (!stacks->B->array)
		return (0);
	ft_init_empty_stack_B(size, stacks);
	stacks->A->size = size;
	stacks->B->size = 0;
	return (1);
}
