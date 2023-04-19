/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:02:47 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/03 17:08:33 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	buffer[5];

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			buffer[0] = i / 10 + '0';
			buffer[1] = i % 10 + '0';
			buffer[2] = ' ';
			buffer[3] = j / 10 + '0';
			buffer[4] = j % 10 + '0';
			write(1, buffer, 5);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
