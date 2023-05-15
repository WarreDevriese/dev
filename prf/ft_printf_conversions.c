/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warredevriese <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:02:16 by warredevriese     #+#    #+#             */
/*   Updated: 2023/05/15 12:35:59 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_signed(int n)
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
		print_len += ft_handle_signed(num / 10);
		print_len += ft_handle_signed(num % 10);
	}
	else
		print_len += ft_putchar(num + '0');
	return (print_len);
}

int	ft_handle_unsigned(unsigned int n)
{
	int	print_len;

	print_len = 0;
	if (n >= 10)
	{
		print_len += ft_handle_unsigned(n / 10);
		print_len += ft_handle_unsigned(n % 10);
	}
	else
		print_len += ft_putchar(n + '0');
	return (print_len);
}

int	ft_handle_hex(unsigned int n, const char format)
{
	int		print_len;
	char	*hex_digits;

	print_len = 0;
	hex_digits = "0123456789abcdef";
	if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (n >= 16)
		print_len += ft_handle_hex(n / 16, format);
	print_len += ft_putchar(hex_digits[n % 16]);
	return (print_len);
}

static int	ft_handle_hex_p(uintptr_t n)
{
	int			print_len;
	const char	*hex_digits;

	print_len = 0;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		print_len += ft_handle_hex_p(n / 16);
	print_len += ft_putchar(hex_digits[n % 16]);
	return (print_len);
}

int	ft_handle_pointer(va_list *args)
{
	uintptr_t	p;
	int			print_len;

	p = (uintptr_t)va_arg(*args, void *);
	if (p == 0)
		print_len = ft_putstr("(nil)");
	else
	{
		print_len = ft_putstr("0x");
		print_len += ft_handle_hex_p(p);
	}
	return (print_len);
}
