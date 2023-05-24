/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:08:03 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/24 16:30:45 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stacks *stacks, short operation)
{
	t_stack	*from_stack;
	t_stack	*to_stack;

	if (operation == PA)
	{
		from_stack = stacks->b;
		to_stack = stacks->a;
	}
	else
	{
		from_stack = stacks->a;
		to_stack = stacks->b;
	}
	if (from_stack->size == 0)
		return ;
	ft_memmove(&to_stack->array[1], &to_stack->array[0], sizeof(short)
		* to_stack->size);
	to_stack->array[0] = from_stack->array[0];
	ft_memmove(&from_stack->array[0], &from_stack->array[1], sizeof(short)
		* (from_stack->size - 1));
	from_stack->array[from_stack->size - 1] = -1;
	from_stack->size--;
	to_stack->size++;
}

static void	ft_swap(t_stacks *stacks, short operation)
{
	short	temp;

	if ((operation == SA || operation == SS) && (stacks->a->size > 1))
	{
		temp = stacks->a->array[0];
		stacks->a->array[0] = stacks->a->array[1];
		stacks->a->array[1] = temp;
	}	
	if ((operation == SB || operation == SS) && (stacks->b->size > 1))
	{
		temp = stacks->b->array[0];
		stacks->b->array[0] = stacks->b->array[1];
		stacks->b->array[1] = temp;
	}
}

static void	ft_rot(t_stacks *stacks, short operation)
{
	short	temp;

	if ((operation == RA || operation == RR) && (stacks->a->size > 1))
	{
		temp = stacks->a->array[stacks->a->size - 1];
		ft_memmove(&stacks->a->array[1], &stacks->a->array[0], sizeof(short)
			* (stacks->a->size - 1));
		stacks->a->array[0] = temp;
	}
	if ((operation == RB || operation == RR) && (stacks->b->size > 1))
	{
		temp = stacks->b->array[stacks->b->size - 1];
		ft_memmove(&stacks->b->array[1], &stacks->b->array[0], sizeof(short)
			* (stacks->b->size - 1));
		stacks->b->array[0] = temp;
	}
}

static void	ft_rrot(t_stacks *stacks, short operation)
{
	short	temp;

	if ((operation == RRA || operation == RRR) && (stacks->a->size > 1))
	{
		temp = stacks->a->array[0];
		ft_memmove(&stacks->a->array[0], &stacks->a->array[1], sizeof(short)
			* (stacks->a->size - 1));
		stacks->a->array[stacks->a->size - 1] = temp;
	}
	if ((operation == RRB || operation == RRR) && (stacks->b->size > 1))
	{
		temp = stacks->b->array[0];
		ft_memmove(&stacks->b->array[0], &stacks->b->array[1], sizeof(short)
			* (stacks->b->size - 1));
		stacks->b->array[stacks->b->size - 1] = temp;
	}
}

void	ft_exec_operation(t_stacks *stacks, short operation)
{
	if (operation == PA || operation == PB)
		ft_push(stacks, operation);
	else if (operation == SA || operation == SB || operation == SS)
		ft_swap(stacks, operation);
	else if (operation == RA || operation == RB || operation == RR)
		ft_rot(stacks, operation);
	else if (operation == RRA || operation == RRB || operation == RRR)
		ft_rrot(stacks, operation);
}
