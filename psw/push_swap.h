/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:02:15 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/20 10:17:07 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//LIBRARIES
# include "libft/inc/libft.h"
# include <limits.h>
# include <stdlib.h>

//OPERATION ID'S
//nullifying operations cancel out (double swaps do not happen)
# define SS = 0
# define SA = 1
# define SB = 2
# define RA = -3
# define RRA = 3
# define RB = -4
# define RRB = 4
# define RR = -5
# define RRR = 5
# define PA = -6
# define PB = 6

//TYPEDEFS
typedef enum e_cases
{
	CASE1,
	CASE2,
	CASE3,
	CASE4
}			t_cases;

typedef struct s_sorting_params
{
	short	cost;
	short	case_nr;
	short	from_pos;
	short	to_pos;
}			t_sorting_params;

typedef struct s_stack
{
	short	*array;
	size_t	size;
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
/* void		ft_sort(t_stacks &stacks); */
void		ft_error(void *ptr);
t_stacks	ft_parse_args(size_t size, char **args);
t_stacks	ft_parse_string(char *argv);
int			ft_init_stacks(size_t size, int *int_array, t_stacks *stacks);
void		ft_free_stacks(t_stacks *stacks);

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
