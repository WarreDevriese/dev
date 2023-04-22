/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:16:00 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/06 15:12:04 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	total_size;

	total_size = nmemb * size;
	p = malloc(total_size);
	if (!p)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
