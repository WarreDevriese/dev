/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 11:41:10 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_operation(t_stack *a, t_stack *b, short operation)
{
	if (operation == SS || operation == RR || operation == RRR)
		ft_twice(a, b, operation);
	else if (operation == SA)
		ft_swap(a);
	else if (operation == SB)
		ft_swap(b);
	else if (operation == PA)
		ft_push(b, a);
	else if (operation == PB)
		ft_push(a, b);
	else if (operation == RA)
		ft_rot(a);
	else if (operation == RB)
		ft_rot(b);
	else if (operation == RRA)
		ft_rrot(a);
	else if (operation == RRB)
		ft_rrot(b);
}
/* void	ft_sort(t_stack *stacks) */
/* { */
/* } */
