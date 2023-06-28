/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/28 16:07:09 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_get_min_pos_val(t_stacks stacks, int *min_pos, int *min_val)
{
    int posA;

	posA = -1;
    *min_pos = -1;
    *min_val = INT_MAX;
    while (++posA < stacks.a->size)
    {
        if (stacks.a->array[posA] < *min_val)
        {
            *min_pos = posA;
            *min_val = stacks.a->array[posA];
        }
    }
}

static void	ft_get_to_pos(int posB, t_stacks stacks, t_sorting_params *sp)
{
	int posA;
	int min_pos;
	int min_val;

	ft_get_min_pos_val(stacks, &min_pos, &min_val);
	sp->to_pos = -1;
	sp->to_val = INT_MAX;
	posA = -1;
	while (++posA < stacks.a->size)
	{
		if (stacks.a->array[posA] > stacks.b->array[posB] &&
				stacks.a->array[posA] < sp->to_val)
		{
			sp->to_pos = posA;
			sp->to_val = stacks.a->array[posA];
		}
	}
	if (sp->to_pos == -1)
	{
		sp->to_pos = min_pos;
		sp->to_val = min_val;
	}
}

static void	ft_get_sorting_params(int posB, t_stacks stacks, t_sorting_params *sp)
{
	int	i;
	int	costs[4];

	sp->from_pos = posB;
	ft_get_to_pos(posB, stacks, sp);
	costs[CASE1] = ft_max((stacks.b->size - sp->from_pos), (stacks.a->size - sp->to_pos));
	costs[CASE2] = ft_max(sp->from_pos, sp->to_pos);
	costs[CASE3] = (stacks.b->size - sp->from_pos) + sp->to_pos;
	costs[CASE4] = sp->from_pos + (stacks.a->size - sp->to_pos);
	i = -1;
	sp->cost = INT_MAX;
	while (++i < 4)
		if (costs[i] < sp->cost)
		{
			sp->from_val = stacks.b->array[posB];
			sp->cost = costs[i];
			sp->case_number = i;
		}
}

static void	ft_get_next_to_sort(t_stacks stacks, t_sorting_params *sp)
{
	int				posB;
	t_sorting_params	temp;

	posB = 0;
	ft_get_sorting_params(posB, stacks, sp);
	while (++posB < stacks.b->size)
	{
		if (posB < sp->cost || posB > stacks.b->size - sp->cost)
		{
			ft_get_sorting_params(posB, stacks, &temp);
			if (temp.cost < sp->cost)
				*sp = temp;
		}
	}
}

void	ft_sort_phase2(t_stacks *stacks)
{
	t_sorting_params	sp;

	while (stacks->b->size)
	{
		ft_get_next_to_sort(*stacks, &sp);
		ft_execute_case(stacks, sp);
		ft_exec_operation(stacks, PA);
	}
}
