/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:01:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 21:54:54 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void *ptr)
{
	if (ptr)
		free(ptr);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stacks(t_stacks *stacks)
{
	if (stacks->a)
	{
		if (stacks->a->array)
			free(stacks->a->array);
		free(stacks->a);
	}
	if (stacks->b)
	{
		if (stacks->b->array)
			free(stacks->b->array);
		free(stacks->b);
	}
}