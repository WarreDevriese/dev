/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:02:15 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/26 11:09:20 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//TAKE OUT PRINTF LATER
# include <stdio.h>

//LIBRARIES
# include "libft/inc/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

//OPERATION ID'S
//nullifying operations cancel out (double swaps do not happen)
# define SS 1
# define SA 2
# define SB 3
# define RA 4
# define RRA 5
# define RB 6
# define RRB 7
# define RR 8
# define RRR 9
# define PA 10
# define PB 11

//TYPEDEFS
# define CASE1 0
# define CASE2 1
# define CASE3 2
# define CASE4 3

typedef struct s_sorting_params
{
	short	cost;
	short	casex;
	short	from_pos;
	short	from_val;
	short	to_pos;
	short	to_val;
}			t_sorting_params;
#define MAX_COST 251

typedef struct s_stack
{
	short	*array;
	short	size;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

typedef struct s_normalizing_params
{
	size_t	i;
	size_t	j;
	size_t	int_max_flag;
	size_t	min_pos;
	int		min_value;
}			t_normalizing_params;

//FUNCTIONS
//GENERAL
void		ft_error(void *ptr);
void		ft_free_stacks(t_stacks *stacks);
//PARSING
void	ft_parse_args(t_stacks *stacks, size_t size, char **args);
void	ft_parse_string(t_stacks *stacks, char *argv);
int			ft_init_stacks(size_t size, int *int_array, t_stacks *stacks);
//OPERATIONS
void		ft_exec_operation(t_stacks *stacks, short operation);
//SORTING
void	ft_sort(t_stacks *stacks);
void	ft_execute_case(t_stacks *stacks, t_sorting_params sp);
/* bool		ft_is_sorted(t_stacks *stacks); */

#endif

/* typedef enum	e_actions */
/* { */
/* 	SA, */
/* 	SB, */
/* 	SS, */
/* 	PA, */
/* 	PB, */
/* 	RA, */
/* 	RB, */
/* 	RR, */
/* 	RRA, */
/* 	RRB, */
/* 	RRR */
/* }				t_actions; */
