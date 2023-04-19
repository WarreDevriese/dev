/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:07:56 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/12 09:26:32 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	x;
	int	len;

	i = 0;
	x = 0;
	len = 0;
	while (sep[i])
		i++;
	while (x < size)
	{
		j = 0;
		while (strs[x][j])
			j++;
		len += i + j;
		x++;
	}
	return (len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(size, strs, sep) + 1);
	if (!dest)
		return (0);
	while (x < size)
	{
		j = 0;
		while (strs[x][j])
			dest[i++] = strs[x][j++];
		j = 0;
		x++;
		while (sep[j] && x < size)
			dest[i++] = sep[j++];
	}
	dest[i] = '\0';
	return (dest);
}
