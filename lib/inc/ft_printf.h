/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:40:45 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 21:45:35 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_strlen(const char *s);
int	ft_putstr(const char *s);
int	ft_putchar(const char c);
int	ft_handle_signed(int n);
int	ft_handle_unsigned(unsigned int n);
int	ft_handle_hex(unsigned int n, const char format);
int	ft_handle_pointer(va_list *args);

#endif
