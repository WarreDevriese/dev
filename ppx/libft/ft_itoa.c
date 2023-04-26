/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:29:37 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/07 12:56:19 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_module(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	return (n);
}

static void	fill_number_str(char *str, unsigned int num)
{
	if (num > 9)
		fill_number_str(str - 1, num / 10);
	*str = (num % 10) + '0';
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	len = get_number_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		*str = '-';
	num = ft_module(n);
	fill_number_str(str + len - 1, num);
	str[len] = '\0';
	return (str);
}
