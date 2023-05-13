/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:17:23 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 14:15:36 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_p(uintptr_t n, const char *hex_digits,
		int *print_len)
{
	if (n >= 16)
		ft_putnbr_base_p(n / 16, hex_digits, print_len);
	ft_putchar(hex_digits[n % 16]);
	(*print_len)++;
}

int	ft_handle_p(va_list *args)
{
	int			print_len;
	uintptr_t	ptr_value;
	const char	*hex_digits;

	hex_digits = "0123456789abcdef";
	ptr_value = (uintptr_t)va_arg(*args, void *);
	if (ptr_value == 0)
		print_len = ft_putstr("(nil)");
	else
	{
		print_len = ft_putstr("0x");
		ft_putnbr_base_p(ptr_value, hex_digits, &print_len);
	}
	return (print_len);
}
