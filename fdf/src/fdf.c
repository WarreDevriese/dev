/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:48:11 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/02 12:28:58 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_iso		**data_array;
	t_dimensions	map;

	(void)argc;
	data_array = get_data(argv[1], &map);
	display_data(data_array, map);
	return (0);
}
