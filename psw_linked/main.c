/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:03:48 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/17 14:06:39 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stackA = init_stack(argv);
	while (!is_sorted(stackA))
	{
		operation = decide_operation(stackA, stackB);
		perform_operation(stackA, stackB, operation);
		print_operation(operation);
	}
}