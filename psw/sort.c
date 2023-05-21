/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/21 11:46:41 by warredevriese    ###   ########.fr       */
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

static signed char	*ft_construct_operation_string(short cmd1_num, signed char cmd1,
  							short cmd2_num, signed char cmd2) 
{
	static signed char		o_string[20000];
	static short			pos; 
	short					i;

	pos = 0;
	while (cmd1_num-- && pos < 20000)
		o_string[pos++] = cmd1;
	while (cmd2_num-- && pos < 20000)
		o_string[pos++] = cmd2;
	if (pos == 19999)
		write(1, "Dude what are you doing", 24);
	return (o_string);
}	
