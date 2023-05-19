/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:42:39 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 17:57:42 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2 || argc > 501)
		exit(0);
	if (argc == 2)
		stacks = ft_parse_string(argv[1]);
	if (argc > 2)
		stacks = ft_parse_args((size_t)(argc - 1), argv + 1);
	/* ft_sort(stacks); */
	for (size_t i = 0; i < stacks.A->size; i++)
    	printf("stacks.A->array[%zu]: %d\n", i, stacks.A->array[i]);
	ft_free_stacks(&stacks);
}
