/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:42:39 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/27 21:36:33 by warredevriese    ###   ########.fr       */
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

void	ft_error(void *ptr)
{
	if (ptr)
		free(ptr);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2 || argc > 501)
		exit(0);
	if (argc == 2)
		ft_parse_string(&stacks, argv[1]);
	if (argc > 2)
		ft_parse_args(&stacks, (size_t)(argc - 1), argv + 1);
	ft_sort(&stacks);
	ft_free_stacks(&stacks);
}
