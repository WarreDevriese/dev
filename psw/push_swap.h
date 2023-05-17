/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:55:01 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/17 15:04:57 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/inc/libft.h"

typedef struct	s_node
{
	int		value;
	struct	s_node *next;
}				t_node;

typedef struct	s_stack
{
	t_node *head;
	t_node *tail;
}				t_stack;

typedef enum	e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	TOTAL
}				t_operations;

int		main(int argc, char **argv);
t_stack	*init_stack(char **argv);
int		is_sorted(t_stack *stack);
int		decide_operation(t_stack *stackA, t_stack *stackB);
void	perform_operation(t_stack *stackA, t_stack *stackB, int operation);
void	print_operation(int operation);
void	swap(t_stack *stack);
void	push(t_stack *from_stack, t_stack *to_stack);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
void	twice(t_stack *stackA, t_stack *stackB, int operation);

#endif
