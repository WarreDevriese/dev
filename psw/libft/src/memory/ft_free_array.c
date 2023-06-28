/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:27:42 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/19 11:43:10 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array, size_t size)
{
	if (!array)
		return ;
	while (size--)
		if (array[size] != NULL)
		{
			free(array[size]);
			array[size] = NULL;
		}
	free(array);
}
