/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warredevriese <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:24:33 by warredevriese     #+#    #+#             */
/*   Updated: 2023/05/27 21:36:39 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stacks *stacks)
{
	if (stacks->a->array[0] != 0)
		ft_exec_operation(stacks, SA);
}

void	ft_sort_three(t_stacks *stacks)
{
	short	*arr;

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
