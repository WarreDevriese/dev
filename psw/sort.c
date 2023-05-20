/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 15:35:48 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stacks *stacks)
{
	short	i;

	if (stacks->b->size)
		return (false);
	i = stacks->a->size;
	while (--i)
		if (stacks->a->array[i] != i)
			return (false);
	return (true);
}

/* last3 */
/* if 012 */ 
/* if 021 r s */
/* if 120 r */
/* if 102 s */
/* if 201 rr */
/* if 210 s r */

/* void	ft_sort(t_stack *stacks) */
/* { */
/* } */
