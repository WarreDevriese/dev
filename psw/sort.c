/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/24 11:09:16 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	ft_get_to_pos(short posA, t_stacks stacks, t_sorting_params *sp)
{
	short	posB;
	short	maxB;

	sp->to_pos = -1;
	posB = -1;
	maxB = stacks.b->size - 1;
	while (++posB < stacks.b->size)
	{
		if (stacks.b->array[posB] > stacks.b->array[maxB])
			maxB = posB;
		if (stacks.b->array[posB] < stacks.a->array[posA]
			&& stacks.b->array[posB] > sp->to_pos)
			sp->to_pos = posB;
		if (stacks.b->array[posB] == stacks.a->array[posA] - 1)
			break ;
	}
	if (stacks.b->size == 0)
		sp->to_pos = 0;
	else if (sp->to_pos == -1)
		sp->to_pos = maxB; 
}

static void	ft_get_sorting_params(short posA, t_stacks stacks, t_sorting_params *sp)
{
	short	i;
	short	costs[4];

	sp->from_pos = posA;
	ft_get_to_pos(posA, stacks, sp);
	costs[CASE1] = ft_max((stacks.a->size - sp->from_pos), (stacks.a->size - sp->to_pos));
	costs[CASE2] = ft_max(sp->from_pos, sp->to_pos);
	costs[CASE3] = (stacks.a->size - sp->from_pos) + sp->to_pos;
	costs[CASE4] = sp->from_pos + (stacks.b->size - sp->to_pos);
	i = -1;
	sp->cost = 251;
	while (++i < 4)
		if (costs[i] < sp->cost)
		{
			sp->cost = costs[i];
			sp->casex = i;
		}
}

static void	ft_get_next_to_sort(t_stacks stacks, t_sorting_params *sp)
{
	short				posA;
	t_sorting_params	temp;

	posA = 0;
	ft_get_sorting_params(posA, stacks, sp);
	while (++posA < stacks.a->size)
	{
		if (posA < sp->cost || posA > stacks.a->size - sp->cost)
		{
			ft_get_sorting_params(posA, stacks, &temp);
			if (temp.cost < sp->cost)
				*sp = temp;
		}
	}
}

void	ft_sort(t_stacks *stacks)
{
	t_sorting_params	sp;

	while (stacks->a->size)
	{
		ft_get_next_to_sort(*stacks, &sp);
		ft_execute_case(stacks, sp);
		ft_exec_operation(stacks, PB);
	}
}

/* last3 */
/* if 012 */ 
/* if 021 r s */
/* if 120 r */
/* if 102 s */
/* if 201 rr */
/* if 210 s r */

/* bool	ft_is_sorted(t_stacks *stacks) */
/* { */
/* 	short	i; */

/* 	if (stacks->b->size) */
/* 		return (false); */
/* 	i = stacks->a->size; */
/* 	while (--i) */
/* 		if (stacks->a->array[i] != i) */
/* 			return (false); */
/* 	return (true); */
/* } */

