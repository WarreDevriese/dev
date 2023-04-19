/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:44:03 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/14 12:26:42 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_u_pf(unsigned int n)
{
	int	print_len;

	print_len = 0;
	if (n >= 10)
	{
		print_len += ft_putnbr_u_pf(n / 10);
		print_len += ft_putnbr_u_pf(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		print_len++;
	}
	return (print_len);
}

int	ft_handle_u(va_list *args)
{
	int				print_len;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	print_len = ft_putnbr_u_pf(n);
	return (print_len);
}
