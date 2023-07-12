/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:29:01 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/13 13:59:03 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	size_t	len;
	int		i;
	int		*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	buffer = (int *)malloc(len * sizeof(int));
	if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (min < max)
		buffer[i++] = min++;
	*range = buffer;
	return (len);
}
