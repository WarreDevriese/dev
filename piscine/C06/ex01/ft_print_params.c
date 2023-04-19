/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:45:22 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/03 19:41:29 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	n;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			ft_putchar(argv[i][n]);
			n++;
		}
		i++;
		ft_putchar('\n');
	}
}
