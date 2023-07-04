/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:17:53 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 15:44:12 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
