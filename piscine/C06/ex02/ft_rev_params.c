/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:02:29 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/03 09:11:04 by wdevries         ###   ########.fr       */
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

	while (argc > 1)
	{
		argc--;
		i = 0;
		while (argv[argc][i])
		{
			ft_putchar(argv[argc][i++]);
		}
		ft_putchar('\n');
	}
}
