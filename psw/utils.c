/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:17:36 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/17 15:05:00 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_operation(t_stack *stackA, t_stack *stackB, int operation)
{
	if (operation == SS || operation == RR || operation == RRR)
		twice(stackA, stackB, operation);
	else if (operation == SA)
		swap(stackA);
	else if (operation == SB)
		swap(stackB);
	else if (operation == PA)
		push(stackB, stackA);
	else if (operation == PB)
		push(stackA, stackB);
	else if (operation == RA)
		rotate(stackA);
	else if (operation == RB)
		rotate(stackB);
	else if (operation == RRA)
		rev_rotate(stackA);
	else if (operation == RRB)
		rev_rotate(stackB);
}

int		is_sorted(t_stack *stack)
{
	t_node	*node;
	
	if (!stack || stack->head)
		return (1);
	node = stack->head;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	print_operation(int operation)
{
	static char	*instructions[TOTAL];

	instructions[SA] = "SA\n";
	instructions[SB] = "SB\n";
	instructions[SS] = "SS\n";
	instructions[PA] = "PA\n";
	instructions[PB] = "PB\n";
	instructions[RA] = "RA\n";
	instructions[RB] = "RB\n";
	instructions[RR] = "RR\n";
	instructions[RRA] = "RRA\n";
	instructions[RRB] = "RRB\n";
	instructions[RRR] = "RRR\n";
	write(1, &instructions[operation], ft_strlen(instructions[operation]));
}
