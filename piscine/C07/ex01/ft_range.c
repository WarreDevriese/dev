/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:29:01 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/12 09:25:06 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	size_t	len;
	int		*range;
	int		i;

	if (min >= max)
		return (0);
	len = max - min;
	range = (int *)malloc(len * sizeof(int));
	if (!range)
		return (0);
	i = 0;
	while (min < max)
		range[i++] = min++;
	return (range);
}
