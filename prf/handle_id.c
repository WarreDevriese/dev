/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:29:07 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 20:32:18 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static unsigned int	ft_module(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	return (n);
}
*/
int	ft_handle_id(int n)
{
	unsigned int	num;
	int				print_len;

	print_len = 0;
	if (n < 0)
	{
		num = -(unsigned int)n;
		print_len += ft_putchar('-');
	}
	else
		num = n;
	if (num >= 10)
	{
		print_len += ft_handle_id(num / 10);
		print_len += ft_handle_id(num % 10);
	}
	else
		print_len += ft_putchar(num + '0');
	return (print_len);
}
/*
int	ft_handle_id(va_list *args)
{
	int	print_len;
	int	n;

	n = va_arg(*args, int);
	print_len = ft_putnbr_pf(n);
	return (print_len);
}
*/
