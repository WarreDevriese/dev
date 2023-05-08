/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xXp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:41:55 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/08 12:20:05 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_x(unsigned int n, const char *hex_digits,
		int *print_len)
{
	if (n >= 16)
		ft_putnbr_base_x(n / 16, hex_digits, print_len);
	ft_putchar(hex_digits[n % 16]);
	(*print_len)++;
}

int	ft_handle_x_lower(va_list *args)
{
	int				print_len;
	unsigned int	n;
	const char		*hex_digits;

	print_len = 0;
	n = va_arg(*args, unsigned int);
	hex_digits = "0123456789abcdef";
	ft_putnbr_base_x(n, hex_digits, &print_len);
	return (print_len);
}

int	ft_handle_x_upper(va_list *args)
{
	int				print_len;
	unsigned int	n;
	const char		*hex_digits;

	print_len = 0;
	n = va_arg(*args, unsigned int);
	hex_digits = "0123456789ABCDEF";
	ft_putnbr_base_x(n, hex_digits, &print_len);
	return (print_len);
}
