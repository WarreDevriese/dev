/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:33:38 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/28 13:16:21 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(t_stacks *stacks)
{
	if (stacks->a->array[0] != 0)
		ft_exec_operation(stacks, SA);
}

void	ft_sort_three(t_stacks *stacks)
{
	int		*arr;

	arr = stacks->a->array;
	while (!(arr[2] > arr[1] && arr[1] > arr[0]))
	{
		if (arr[1] > arr[2] && arr[2] > arr[0])
			ft_exec_operation(stacks, RRA);
		else if (arr[1] > arr[0] && arr[0] > arr[2])
			ft_exec_operation(stacks, RRA);
		else if (arr[2] > arr[0] && arr[0] > arr[1])
			ft_exec_operation(stacks, SA);
		else if (arr[0] > arr[2] && arr[2] > arr[1])
			ft_exec_operation(stacks, RA);
		else if (arr[0] > arr[1] && arr[1] > arr[2])
			ft_exec_operation(stacks, SA);
	}
}

static void	ft_orient(t_stacks *stacks)
{
	int		i;

	i = 0;
	while (stacks->a->array[i] != 0 && stacks->a->array[i] < stacks->a->size - 1)
		i++;
	if (i <= stacks->a->size / 2)
		while (stacks->a->array[0] != 0)
			ft_exec_operation(stacks, RA);
	else
		while (stacks->a->array[0] != 0)
			ft_exec_operation(stacks, RRA);
}

void	ft_sort(t_stacks *stacks)
{
	if (ft_is_sorted(stacks))
		return ;
	if (stacks->a->size == 2)
		ft_sort_two(stacks);
	else if (stacks->a->size == 3)
		ft_sort_three(stacks);
	else
	{
		ft_sort_phase1(stacks);
		ft_sort_phase2(stacks);
		ft_orient(stacks);
	}
}
