/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:48:11 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/30 15:11:04 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_iso		**data_array;
	t_dimensions	map;

	//add error handling for input
	(void)argc;
	data_array = get_data(argv[1], &map);
	display_data(data_array, map);
	return (0);
}
