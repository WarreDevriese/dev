/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_phase2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/03 20:46:59 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_to_pos(t_sorting_params *sp, short to_pos, short to_val)
{
	sp->to_pos = to_pos;
	sp->to_val = to_val;
}

static void	ft_get_to_pos2(t_stacks stacks, t_sorting_params *sp)
{
	short posA;
	short min_pos;
	short min_val;

	min_pos = -1;
	min_val = SHRT_MAX;
	sp->to_pos = -1;
	sp->to_val = SHRT_MAX;
	posA = -1;
	while (++posA < stacks.a->size)
	{
		if (stacks.a->array[posA] < min_val)
			min_pos = posA;
		if (stacks.a->array[posA] < min_val)
			min_val = stacks.a->array[posA];
		if (stacks.a->array[posA] > stacks.b->array[0] &&
				stacks.a->array[posA] < sp->to_val)
			ft_set_to_pos(sp, posA, stacks.a->array[posA]);
	}
	if (sp->to_pos == -1)
		ft_set_to_pos(sp, min_pos, min_val);
}

static void	ft_position_stackb(t_stacks *stacks)
{
	short	i;
	short	max_pos;
	short	max_val;

	i = -1;
	max_pos = -1;
	max_val = -1;
	while (++i < stacks->b->size)
		if (stacks->b->array[i] > max_val)
		{
			max_pos = i;
			max_val = stacks->b->array[i];
		}
	if (max_pos <= stacks->b->size / 2)
		while (stacks->b->array[0] != max_val)
			ft_exec_operation(stacks, RB);
	else
		while (stacks->b->array[0] != max_val)
			ft_exec_operation(stacks, RRB);
}

static void	ft_position_stacka(t_stacks *stacks)
{
	short	i;

	i = 0;
	while (stacks->a->array[i] != 0)
		i++;
	if (i <= stacks->a->size / 2)
		while (stacks->a->array[0] != 0)
			ft_exec_operation(stacks, RA);
	else
		while (stacks->a->array[0] != 0)
			ft_exec_operation(stacks, RRA);
}

/* static void    ft_print_stacks(t_stacks *stacks) */
/* { */
/*     short i; */

/* 	printf("\n"); */
/*     printf("Stack A: \n"); */
/*     for(i = 0; i < stacks->a->size; i++) */
/*         printf("%d ", stacks->a->array[i]); */
/*     printf("\n"); */

/*     printf("Stack B: \n"); */
/*     for(i = 0; i < stacks->b->size; i++) */
/*         printf("%d ", stacks->b->array[i]); */
/*     printf("\n\n"); */
/* } */

void	ft_sort_phase2(t_stacks *stacks)
{
	t_sorting_params	sp;
	ft_position_stackb(stacks);
	while (stacks->b->size)
	{
		/* ft_print_stacks(stacks); */
		if (stacks->a->array[0] != stacks->b->array[0] + 1)
		{
			ft_get_to_pos2(*stacks, &sp);
			if (sp.to_pos <= stacks->a->size / 2)
				while (stacks->a->array[0] != sp.to_val)
					ft_exec_operation(stacks, RA);
			else
				while (stacks->a->array[0] != sp.to_val)
					ft_exec_operation(stacks, RRA);
		}
		ft_exec_operation(stacks, PA);
	}
	ft_position_stacka(stacks);
}
