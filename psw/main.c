/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:42:39 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 21:31:34 by warredevriese    ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2 || argc > 501)
		exit(0);
	if (argc == 2)
		ft_parse_string(&stacks, argv[1]);
	if (argc > 2)
		ft_parse_args(&stacks, (size_t)(argc - 1), argv + 1);
	ft_free_stacks(&stacks);
}
