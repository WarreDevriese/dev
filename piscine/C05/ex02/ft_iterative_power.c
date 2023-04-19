/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:03:31 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/08 10:17:41 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	num;

	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = 0;
	num = 1;
	while (i < power)
	{
		num *= nb;
		i++;
	}
	return (num);
}
