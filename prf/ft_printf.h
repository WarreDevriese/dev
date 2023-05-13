/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:40:45 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 13:59:36 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_strlen(const char *s);
int		ft_putstr(const char *s);
int		ft_handle_s(va_list *args);
int		ft_handle_c(va_list *args);
int		ft_handle_id(va_list *args);
int		ft_handle_u(va_list *args);
int		ft_handle_x(va_list *args, const char format);
int		ft_handle_p(va_list *args);
int		ft_putchar(const char c);

#endif
