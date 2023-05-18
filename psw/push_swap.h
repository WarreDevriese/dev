/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:02:15 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/18 22:03:05 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//STACK ID'S
# define A = 0
# define B = 1

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

typedef enum	e_cases
{
	CASE1,		//RR
	CASE2, 		//RRR
	CASE3, 		//RA + RRB
	CASE4  		//RRA + RB
}				t_cases;

typedef struct	s_params
{
	short	cost;
	short 	CASE;
	short	from_pos;
	short	to_pos;
}				t_params;

typedef struct	s_stack
{
	short	*array;
	short	size;
}				t_stack;

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

