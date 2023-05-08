/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:19:32 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/19 14:51:38 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	if (!dest && !src)
		return (0);
	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	while (n--)
		*pd++ = *ps++;
	return (dest);
}
