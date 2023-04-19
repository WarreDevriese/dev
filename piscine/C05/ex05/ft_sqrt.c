/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:43:16 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/08 16:56:39 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	low;
	long long	high;
	long long	mid;
	long long	square;
	long long	nbr;

	nbr = nb;
	low = 0;
	high = nb;
	if (nb < 0)
		return (0);
	while (low <= high)
	{
		mid = (low + high) / 2;
		square = mid * mid;
		if (square == nbr)
			return (mid);
		else if (square < nbr)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (0);
}
