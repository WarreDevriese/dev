/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:28:46 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/04 14:36:29 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (pd == ps || n == 0)
	{
		return (dest);
	}
	if (pd < ps)
	{
		while (n--)
			*pd++ = *ps++;
	}
	if (pd > ps)
	{
		while (n--)
			pd[n] = ps[n];
	}
	return (dest);
}
