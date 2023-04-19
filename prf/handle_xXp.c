/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xXp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:41:55 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/14 14:33:30 by wdevries         ###   ########.fr       */
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

static void	ft_putnbr_base_p(uintptr_t n, const char *hex_digits,
		int *print_len)
{
	if (n >= 16)
		ft_putnbr_base_p(n / 16, hex_digits, print_len);
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

int	ft_handle_p(va_list *args)
{
	int			print_len;
	uintptr_t	ptr_value;
	const char	*hex_digits;

	hex_digits = "0123456789abcdef";
	ptr_value = (uintptr_t)va_arg(*args, void *);
	if (ptr_value == 0)
	{
		ft_putstr("0x0");
		print_len = 3;
	}
	else
	{
		ft_putstr("0x");
		print_len = 2;
		ft_putnbr_base_p(ptr_value, hex_digits, &print_len);
	}
	return (print_len);
}
