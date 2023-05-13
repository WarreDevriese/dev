/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:55:19 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 21:45:04 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char *ptr, va_list *args)
{
	int	print_len;

	print_len = 0;
	if (*ptr == 'c')
		print_len = ft_putchar((char)va_arg(*args, int));
	else if (*ptr == 's')
		print_len = ft_putstr(va_arg(*args, const char *));
	else if (*ptr == 'd' || *ptr == 'i')
		print_len = ft_handle_signed(va_arg(*args, int));
	else if (*ptr == 'u')
		print_len = ft_handle_unsigned(va_arg(*args, unsigned int));
	else if (*ptr == 'p')
		print_len = ft_handle_pointer(args);
	else if (*ptr == 'x' || *ptr == 'X')
		print_len = ft_handle_hex(va_arg(*args, unsigned int), *ptr);
	else if (*ptr == '%')
		print_len = ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *format_string, ...)
{
	int			print_len;
	const char	*ptr;
	va_list		args;

	va_start(args, format_string);
	ptr = format_string;
	print_len = 0;
	while (*ptr)
	{
		if (*ptr == '%')
			print_len += ft_parse(++ptr, &args);
		else
			print_len += ft_putchar(*ptr);
		ptr++;
	}
	va_end(args);
	return (print_len);
}
