/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:21:10 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/12 09:16:18 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	doublechar(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	writenbr(long nbr, int bv, char *base)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			writenbr(-(nbr / bv), bv, base);
			ft_putchar(base[-(nbr % bv)]);
			return ;
		}
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= bv)
		writenbr(nbr / bv, bv, base);
	ft_putchar(base[nbr % bv]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	bv;

	bv = 0;
	while (base[bv])
	{
		if (base[bv] == '+' || base[bv] == '-')
			return ;
		else if (base[bv] < 33 || base[bv] == 127)
			return ;
		++bv;
	}
	if (bv < 2)
		return ;
	if (doublechar(base))
		return ;
	writenbr((long)nbr, bv, base);
}
