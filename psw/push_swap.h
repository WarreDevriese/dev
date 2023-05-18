/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:02:15 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/18 17:14:38 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A = 0
# define B = 1

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
	RRR
}				t_operations;

typedef enum	e_cases
{
	CASE1,
	CASE2,
	CASE3,
	CASE4
}				t_cases;

//index: normalized value of input;
//pos: desired position in opposite stack;
//cost: min amount of operations to achieve pos;
//CASE: set of operations to achieve pos;
typedef struct	s_element
{
	unsigned short	index;
	unsigned short	pos;
	unsigned short	cost;
	unsigned short 	CASE;
}				t_element;

//size: current amount of elements in stack;
typedef struct	s_stack
{
	t_element		*array;
	unsigned short	size;
}				t_stack;

#endif
