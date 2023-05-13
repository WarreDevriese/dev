/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:44:03 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 20:31:25 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_u(unsigned int n)
{
	int	print_len;

	print_len = 0;
	if (n >= 10)
	{
		print_len += ft_handle_u(n / 10);
		print_len += ft_handle_u(n % 10);
	}
	else
		print_len += ft_putchar(n + '0');
	return (print_len);
}
