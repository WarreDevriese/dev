/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:50:45 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 20:15:15 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(char c)
{
	return (ft_putchar((char)va_arg(*args, int)));
}

int	ft_handle_s(va_list *args)
{
	const char	*s;

	s = va_arg(*args, const char *);
	if (s == NULL)
		s = "(null)";
	return (ft_putstr(s));
}
