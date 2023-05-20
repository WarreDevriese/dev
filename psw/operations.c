/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:50:51 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 11:41:10 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	short	temp;

	if (stack->size < 2)
		return ;
	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
}

void	ft_push(t_stack *from_stack, t_stack *to_stack)
{
	if (from_stack->size == 0)
		return ;
	ft_memmove(&to_stack->array[1], &to_stack->array[0], sizeof(short) * to_stack->size);
	to_stack->array[0] = from_stack->array[0];
	ft_memmove(&from_stack->array[0], &from_stack->array[1], sizeof(short) * (from_stack->size - 1));
	from_stack->array[from_stack->size - 1] = -1;
	from_stack->size--;
	to_stack->size++;
}

void	ft_rot(t_stack *stack)
{
	short	temp;

	if (stack->size < 2)
		return ;
	temp = stack->array[0];
	ft_memmove(&stack->array[0], &stack->array[1], sizeof(short) * (stack->size - 1));
	stack->array[stack->size - 1] = temp;
}

void	ft_rrot(t_stack *stack)
{
	short	temp;

	if (stack->size < 2)
		return ;
	temp = stack->array[stack->size - 1];
	ft_memmove(&stack->array[1], &stack->array[0], sizeof(short) * (stack->size - 1));
	stack->array[0] = temp;
}

void	ft_twice(t_stack *a, t_stack *b, short operation)
{
	if (operation == SS)
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (operation == RR)
	{
		ft_rot(a);
		ft_rot(b);
	}
	else if (operation == RRR)
	{
		ft_rrot(a);
		ft_rrot(b);
	}
}
