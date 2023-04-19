/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:26:33 by wdevries          #+#    #+#             */
/*   Updated: 2023/03/11 10:46:35 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(char comb[], int size, int end)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putchar(comb[i++]);
	if (comb[0] == end)
	{
		write(1, "\n", 1);
		return ;
	}
	else
		write(1, ", ", 2);
}

void	meat(char comb[], char combmax[], int n)
{
	int	base;
	int	flag;

	while (comb[0] != combmax[0])
	{
		flag = n - 1;
		while (comb[flag] == combmax[flag])
			--flag;
		base = ++(comb[flag]);
		while (flag < n - 1)
			comb[++flag] = ++base;
		print_array(comb, n, combmax[0]);
	}
}

void	ft_print_combn(int n)
{
	char	comb[9];
	char	combmax[9];
	int		i;

	if (n < 1 || n > 9)
		return ;
	i = 0;
	while (i < n)
	{
		comb[i] = i + '0';
		combmax[i] = (10 - n) + i + '0';
		i++;
	}
	print_array(comb, n, combmax[0]);
	meat(comb, combmax, n);
}

int		main(void)
{
	ft_print_combn(1);
	write(1, "\n", 1);
	ft_print_combn(2);
	write(1, "\n", 1);
        ft_print_combn(3);
	write(1, "\n", 1);
        ft_print_combn(4);
	write(1, "\n", 1);
        ft_print_combn(5);
	write(1, "\n", 1);
        ft_print_combn(6);
	write(1, "\n", 1);
        ft_print_combn(7);
	write(1, "\n", 1);
        ft_print_combn(8);
	write(1, "\n", 1);
        ft_print_combn(9);

}
