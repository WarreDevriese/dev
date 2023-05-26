/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:57:57 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/26 12:55:50 by wdevries         ###   ########.fr       */
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

static void	ft_init_normalized_stack(size_t size, int *int_array, t_stacks *stacks)
{
	size_t	i;
	size_t	j;
	short	index;

	i = -1;
	while (++i < size)
	{
		j = -1;
		index = 0;
		while (++j < size)
			if (int_array[j] < int_array[i])
				index++;
		stacks->a->array[i] = index;
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
