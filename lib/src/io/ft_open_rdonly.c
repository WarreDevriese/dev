/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_rdonly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:41:16 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/28 18:44:00 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_open_rdonly(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
}
