/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/24 17:25:54 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* static void	ft_get_to_pos(short posA, t_stacks stacks, t_sorting_params *sp) */
/* { */
/* 	short	posB; */
/* 	short	maxB; */

/* 	posB = -1; */
/* 	maxB = stacks.b->size - 1; */
/* 	sp->to_pos = -1; */
/* 	while (++posB < stacks.b->size) */
/* 	{ */
/* 		if (stacks.b->array[posB] > stacks.b->array[maxB]) */
/* 			maxB = posB; */
/* 		if (stacks.b->array[posB] < stacks.a->array[posA] */
/* 			&& (sp->to_pos == -1 || */
/* 				stacks.b->array[posB] > stacks.b->array[sp->to_pos])) */
/* 			sp->to_pos = posB; */
/* 		if (stacks.b->array[posB] == stacks.a->array[posA] - 1) */
/* 			break ; */
/* 	} */
/* 	if (stacks.b->size == 0) */
/* 		sp->to_pos = 0; */
/* 	else if (sp->to_pos == -1) */
/* 		sp->to_pos = maxB; */ 
/* } */

static void	ft_get_to_pos(short posA, t_stacks stacks, t_sorting_params *sp)
{
	short posB;
	short maxB;
	short maxB_value;
	short to_pos_value;

	posB = 0;
	maxB = -1;
	maxB_value = SHRT_MIN;
	to_pos_value = SHRT_MIN;
	sp->to_pos = -1;
	while (posB < stacks.b->size)
	{
		if (stacks.b->array[posB] > maxB_value)
		{
			maxB = posB;
			maxB_value = stacks.b->array[posB];
		}
		if (stacks.b->array[posB] < stacks.a->array[posA] &&
				stacks.b->array[posB] > to_pos_value)
		{
			sp->to_pos = posB;
			to_pos_value = stacks.b->array[posB];
		}
		posB++;
	}
	if (sp->to_pos == -1)
		sp->to_pos = maxB;
	if (stacks.b->size == 0)
		sp->to_pos = 0;
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
		/* if (posA < sp->cost || posA > stacks.a->size - sp->cost) */
		/* { */
		ft_get_sorting_params(posA, stacks, &temp);
		if (temp.cost < sp->cost)
			*sp = temp;
		/* } */
	}
}

static void    ft_print_stacks(t_stacks *stacks)
{
    short i;

    printf("Stack A: \n");
    for(i = 0; i < stacks->a->size; i++)
        printf("%d ", stacks->a->array[i]);
    printf("\n");

    printf("Stack B: \n");
    for(i = 0; i < stacks->b->size; i++)
        printf("%d ", stacks->b->array[i]);
    printf("\n");
}

static void    ft_print_sorting_params(t_sorting_params sp)
{
    printf("Sorting Params: \n");
    printf("from_pos: %d\n", sp.from_pos);
    printf("to_pos: %d\n", sp.to_pos);
    printf("cost: %d\n", sp.cost);
    printf("casex: %d\n", sp.casex);
}

void	ft_sort(t_stacks *stacks)
{
	t_sorting_params	sp;

	while (stacks->a->size)
	{
		ft_print_stacks(stacks);
		ft_get_next_to_sort(*stacks, &sp);
		ft_print_sorting_params(sp);
		ft_execute_case(stacks, sp);
		ft_exec_operation(stacks, PB);
		write(1, "PB\n", 3);
		ft_print_stacks(stacks);
    	printf("\n\n\n\n");
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

