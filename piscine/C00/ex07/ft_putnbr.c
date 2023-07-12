/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:54:11 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/03 17:10:06 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int num)
{
	int		i;
	long	nb;
	char	buffer[11];

	nb = num;
	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		buffer[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
	}	
}
