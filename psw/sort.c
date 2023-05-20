/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 13:50:46 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stacks *stacks)
{
	short	i;

	//THIS LINE IS UNTESTED
	if (stacks->b->size)
		return (false);
	i = stacks->a->size;
	while (--i)
		if (stacks->a->array[i] != i)
			return (false);
	return (true);
}

/* void	ft_sort(t_stack *stacks) */
/* { */
/* } */
