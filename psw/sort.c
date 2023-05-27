/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/27 11:44:53 by wdevries         ###   ########.fr       */
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
static void	ft_b_to_a(t_stacks *stacks)
{
	short	i;

	i = 0;
	while (stacks->b->array[i] != stacks->b->size - 1)
		i++;
	if (i <= stacks->b->size / 2)
		while (stacks->b->array[0] != stacks->b->size - 1)
			ft_exec_operation(stacks, RB);
	else
		while (stacks->b->array[0] != stacks->b->size - 1)
			ft_exec_operation(stacks, RRB);
	while (stacks->b->size)
		ft_exec_operation(stacks, PA);
}

static void	ft_sort_two(t_stacks *stacks)
{
	if (stacks->a->array[0] != 0)
		ft_exec_operation(stacks, SA);
}

static void	ft_sort_three(t_stacks *stacks)
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

void	ft_sort(t_stacks *stacks)
{
	t_sorting_params	sp;

	if (stacks->a->size == 2)
		ft_sort_two(stacks);
	if (stacks->a->size == 3)
		ft_sort_three(stacks);
	if (stacks->a->size > 3)
	{
		while (stacks->a->size)
		{
			ft_get_next_to_sort(*stacks, &sp);
			ft_execute_case(stacks, sp);
			ft_exec_operation(stacks, PB);
		}
		ft_b_to_a(stacks);
	}
	/* ft_print_stacks(stacks); */
}

/* static void    ft_print_stacks(t_stacks *stacks) */
/* { */
/*     short i; */

/*     printf("Stack A: \n"); */
/*     for(i = 0; i < stacks->a->size; i++) */
/*         printf("%d ", stacks->a->array[i]); */
/*     printf("\n"); */

/*     printf("Stack B: \n"); */
/*     for(i = 0; i < stacks->b->size; i++) */
/*         printf("%d ", stacks->b->array[i]); */
/*     printf("\n"); */
/* } */

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

