/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:01:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 17:04:24 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error()
{
	write(2, "Error\n", 6);
	exit (1);
}

void ft_free_stacks(t_stacks *stacks)
{
    if (stacks->A) 
    {
        if (stacks->A->array)
            free(stacks->A->array);
        free(stacks->A);
    }

    if (stacks->B)
    {
        if (stacks->B->array)
            free(stacks->B->array);
        free(stacks->B);
    }
}
