/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:09:34 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:31 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_frame_info(t_frame_info *frame_info, t_iso data_array, t_dimensions map)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if	(data_array[i][j].x < frame_info->min_x || (i == 0 && j == 0))
				frame_info->min_x = data_array[i][j].x;
			if	(data_array[i][j].x > frame_info->max_x || (i == 0 && j == 0))
				frame_info->max_x = data_array[i][j].x;
			if	(data_array[i][j].y < frame_info->min_y || (i == 0 && j == 0))
				frame_info->min_y = data_array[i][j].y;
			if	(data_array[i][j].y > frame_info->max_y || (i == 0 && j == 0))
				frame_info->max_y = data_array[i][j].y;
			j++;
		}
		i++;
	}
	frame_info->x_range = frame_info->max_x - frame_info->min_x;
	frame_info->y_range = frame_info->max_y - frame_info->min_y;
}

void	display_data(t_iso **data_array, t_dimensions map)
{
	t_mlx_params fdf;
	size_t	i;
	size_t	j;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1920, 1920, "Fil de Fer");
	fdf.img = mlx_new_image(fdf.mlx, 1920, 1920);

		mlx_loop(fdf. mlx);
}
