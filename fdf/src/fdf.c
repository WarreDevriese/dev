/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:48:11 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/09 16:40:59 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_data_array(t_iso ***data_array, size_t height) 
{
    size_t i;

	i = 0;
    while (i < height)
        free((*data_array)[i++]);
    free(*data_array);
	printf("%s\n", "Data successfully freed");
}

int		main(int argc, char **argv)
{
	t_iso		**data_array;
	t_dimensions	map;
	t_frame_info	frame_info;

	(void)argc;
	data_array = get_data(argv[1], &map);
	get_frame_info(&frame_info, data_array, map);
	apply_scaling(frame_info, &data_array, map); 
	display_data();
	return (0);
}
