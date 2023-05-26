/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:19:44 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/26 12:38:04 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_case1(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->a->array[0] != sp.from_val && stacks->b->array[0] != sp.to_val)
	{
		ft_exec_operation(stacks, RR);
		write(1, "rr\n", 3);
	}
	if (stacks->b->array[0] == sp.to_val)
	{	
		while (stacks->a->array[0] != sp.from_val)
		{
			ft_exec_operation(stacks, RA);
			write(1, "ra\n", 3);
		}
	}
	else
	{	
		while (stacks->b->array[0] != sp.to_val)
		{
			ft_exec_operation(stacks, RB);
			write(1, "rb\n", 3);
		}
	}
}

static void	ft_case2(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->a->array[0] != sp.from_val && stacks->b->array[0] != sp.to_val)
	{
		ft_exec_operation(stacks, RRR);
		write(1, "rrr\n", 4);
	}
	if (stacks->b->array[0] == sp.to_val)
	{
		while (stacks->a->array[0] != sp.from_val)

		{
			ft_exec_operation(stacks, RRA);
			write(1, "rra\n", 4);
		}
	}
	else
	{	
		while (stacks->b->array[0] != sp.to_val)
		{
			ft_exec_operation(stacks, RRB);
			write(1, "rrb\n", 4);
		}
	}
}

static void	ft_case3(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->a->array[0] != sp.from_val)
	{
		ft_exec_operation(stacks, RA);
		write(1, "ra\n", 3);
	}
	while (stacks->b->array[0] != sp.to_val)
	{
		ft_exec_operation(stacks, RRB);
		write(1, "rrb\n", 4);
	}
}

static void	ft_case4(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->a->array[0] != sp.from_val)
	{
		ft_exec_operation(stacks, RRA);
		write(1, "rra\n", 4);
	}
	while (stacks->b->array[0] != sp.to_val)
	{
		ft_exec_operation(stacks, RB);
		write(1, "rb\n", 3);
	}
}

void	ft_execute_case(t_stacks *stacks, t_sorting_params sp)
{
	if (sp.casex == CASE1)
		ft_case1(stacks, sp);
	else if (sp.casex == CASE2)
		ft_case2(stacks, sp);
	else if (sp.casex == CASE3)
		ft_case3(stacks, sp);
	else if (sp.casex == CASE4)
		ft_case4(stacks, sp);
}
