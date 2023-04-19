/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:29:07 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/14 12:16:12 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_module(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	return (n);
}

static int	ft_putnbr_pf(int n)
{
	unsigned int	num;
	int				print_len;

	print_len = 0;
	if (n < 0)
	{
		ft_putchar('-');
		print_len++;
	}
	num = ft_module(n);
	if (num >= 10)
	{
		print_len += ft_putnbr_pf(num / 10);
		print_len += ft_putnbr_pf(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
		print_len++;
	}
	return (print_len);
}

int	ft_handle_id(va_list *args)
{
	int	print_len;
	int	n;

	n = va_arg(*args, int);
	print_len = ft_putnbr_pf(n);
	return (print_len);
}
