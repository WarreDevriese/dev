/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs%.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:50:45 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/14 13:30:06 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	ft_putchar(c);
	return (1);
}

int	ft_handle_s(va_list *args)
{
	const char	*s;

	s = va_arg(*args, const char *);
	if (s == NULL)
		s = "(null)";
	ft_putstr(s);
	return (ft_strlen(s));
}
