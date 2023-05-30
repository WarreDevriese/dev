/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_phase1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/30 08:35:47 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_to_pos(t_sorting_params *sp, short to_pos, short to_val)
{
	sp->to_pos = to_pos;
	sp->to_val = to_val;
}

static void	ft_get_to_pos(short posA, t_stacks stacks, t_sorting_params *sp)
{
	short posB;
	short max_pos;
	short max_val;

	max_pos = -1;
	max_val = SHRT_MIN;
	sp->to_pos = -1;
	sp->to_val = SHRT_MIN;
	posB = -1;
	while (++posB < stacks.b->size)
	{
		if (stacks.b->array[posB] > max_val)
			max_pos = posB;
		if (stacks.b->array[posB] > max_val)
			max_val = stacks.b->array[posB];
		if (stacks.b->array[posB] < stacks.a->array[posA] &&
				stacks.b->array[posB] > sp->to_val)
			ft_set_to_pos(sp, posB, stacks.b->array[posB]);
	}
	if (sp->to_pos == -1)
		ft_set_to_pos(sp, max_pos, max_val);
	if (stacks.b->size == 0)
		ft_set_to_pos(sp, 0, -1);
}

static void	ft_get_sorting_params(short posA, t_stacks stacks, t_sorting_params *sp)
{
	short	i;
	short	costs[4];

	sp->from_pos = posA;
	ft_get_to_pos(posA, stacks, sp);
	costs[CASE1] = ft_max((stacks.a->size - sp->from_pos), (stacks.b->size - sp->to_pos));
	costs[CASE2] = ft_max(sp->from_pos, sp->to_pos);
	costs[CASE3] = (stacks.a->size - sp->from_pos) + sp->to_pos;
	costs[CASE4] = sp->from_pos + (stacks.b->size - sp->to_pos);
	i = -1;
	sp->cost = MAX_COST;
	while (++i < 4)
		if (costs[i] < sp->cost)
		{
			sp->from_val = stacks.a->array[posA];
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
		ft_get_sorting_params(posA, stacks, &temp);
		if (temp.cost < sp->cost)
			*sp = temp;
	}
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

void	ft_sort(t_stacks *stacks)
{
	t_sorting_params	sp;

	if (ft_is_sorted(stacks))
		return ;
	if (stacks->a->size == 2)
		ft_sort_two(stacks);
	else if (stacks->a->size == 3)
		ft_sort_three(stacks);
	else if (stacks->a->size > 3)
	{
		while (stacks->a->size > 3)
		{
			/* ft_print_stacks(stacks); */
			ft_get_next_to_sort(*stacks, &sp);
			ft_execute_case(stacks, sp);
			ft_exec_operation(stacks, PB);
		}
		ft_sort_three(stacks);
		ft_sort_phase2(stacks);
	}
	/* if (ft_is_sorted(stacks)) */
	/* 	printf("SUCCES"); */
	/* else */
	/* 	printf("FAIL"); */
}
