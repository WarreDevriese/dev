/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:38:30 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/17 13:39:36 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first_node = stack->head;
	second_node = stack->head->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	stack->head = second_node;
	if (first_node->next == NULL)
		stack->tail = first_node;
}

void	push(t_stack *from_stack, t_stack *to_stack)
{
	t_node	*node;

	if (!from_stack || !from_stack->head)
		return ;
	node = from_stack->head;
	from_stack->head = node->next;
	if (from_stack->head == NULL)
		from_stack->tail = NULL;
	node->next = to_stack->head;
	to_stack->head = node;
	if (to_stack->tail == NULL)
		to_stack->tail = node;
}

void	rotate(t_stack *stack)
{
	t_node	*top_node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	top_node = stack->head;
	stack->head = top_node->next;
	top_node->next = NULL;
	stack->tail->next = top_node;
	stack->tail = top_node;
}

void	rev_rotate(t_stack *stack)
{
	t_node	*last_node;
	t_node	*current_node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	current_node = stack->head;
	while (current_node->next != stack->tail)
		current_node = current_node->next;
	last_node = stack->tail;
	stack->tail = current_node;
	current_node->next = NULL;
	last_node->next = stack->head;
	stack->head = last_node;
}

void	twice(t_stack *stackA, t_stack *stackB, int operation)
{
	if (operation == SS)
	{
		swap(stackA);
		swap(stackB);
	}
	else if (operation == RR)
	{
		rotate(stackA);
		rotate(stackB);
	}
	else if (operation == RRR)
	{
		rev_rotate(stackA);
		rev_rotate(stackB);
	}
}
