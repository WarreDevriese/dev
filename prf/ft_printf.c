/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:55:19 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/09 13:45:04 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char *ptr, va_list *args)
{
	int	print_len;

	if (*ptr == 'c')
		print_len = ft_handle_c(args);
	else if (*ptr == 's')
		print_len = ft_handle_s(args);
	else if (*ptr == 'p')
		print_len = ft_handle_p(args);
	else if (*ptr == 'd' || *ptr == 'i')
		print_len = ft_handle_id(args);
	else if (*ptr == 'u')
		print_len = ft_handle_u(args);
	else if (*ptr == 'x')
		print_len = ft_handle_x_lower(args);
	else if (*ptr == 'X')
		print_len = ft_handle_x_upper(args);
	else if (*ptr == '%')
		print_len = ft_putchar_pf('%');
	else
		print_len = write(2, "[INVALID FORMAT SPECIFIER]", 26);
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
		{
			ptr++;
			print_len += ft_parse(ptr, &args);
		}
		else
		{
			print_len += ft_putchar_pf(*ptr);
		}
		ptr++;
	}
	va_end(args);
	return (print_len);
}
