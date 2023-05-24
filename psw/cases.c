/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:19:44 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/24 11:50:37 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_case1(t_stacks *stacks, t_sorting_params sp)
{
	short	i;

	i = 0;
	while (i++ < ft_min((stacks->a->size - sp.from_pos), (stacks->b->size - sp.to_pos)))
	{
		ft_exec_operation(stacks, RR);
		write(1, "RR\n", 3);
	}
	i = 0;
	if ((stacks->a->size - sp.from_pos) > (stacks->b->size - sp.to_pos))
		while (i++ < (sp.to_pos - sp.from_pos))
		{
			ft_exec_operation(stacks, RA);
			write(1, "RA\n", 3);
		}
	else
		while (i++ < (sp.from_pos - sp.to_pos))
		{
			ft_exec_operation(stacks, RB);
			write(1, "RB\n", 3);
		}
}

static void	ft_case2(t_stacks *stacks, t_sorting_params sp)
{
	short	i;

	i = 0;
	while (i++ < ft_min(sp.from_pos, sp.to_pos))
	{
		ft_exec_operation(stacks, RRR);
		write(1, "RRR\n", 4);
	}
	i = 0;
	if (sp.from_pos > sp.to_pos)
		while (i++ < (sp.to_pos - sp.from_pos))
		{
			ft_exec_operation(stacks, RRA);
			write(1, "RRA\n", 4);
		}
	else
		while (i++ < (sp.from_pos - sp.to_pos))
		{
			ft_exec_operation(stacks, RRB);
			write(1, "RRB\n", 4);
		}
}

static void	ft_case3(t_stacks *stacks, t_sorting_params sp)
{
	short	i;

	i = 0;
	while (i++ < (stacks->a->size - sp.from_pos))
	{
		ft_exec_operation(stacks, RA);
		write(1, "RA\n", 3);
	}
	i = 0;
	while (i++ < sp.to_pos)
	{
		ft_exec_operation(stacks, RRB);
		write(1, "RRB\n", 4);
	}
}

static void	ft_case4(t_stacks *stacks, t_sorting_params sp)
{
	short	i;

	i = 0;
	while (i++ < sp.from_pos)
	{
		ft_exec_operation(stacks, RRA);
		write(1, "RRA\n", 4);
	}
	i = 0;
	while (i++ < (stacks->b->size - sp.to_pos))
	{
		ft_exec_operation(stacks, RB);
		write(1, "RB\n", 3);
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
