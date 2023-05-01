/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:09:34 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/01 13:33:06 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_frame_info(t_frame_info *frame_info, t_iso **data_array, t_dimensions map)
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

static void	put_pixels(t_frame_info frame_info, t_iso **data_array, t_dimensions map, t_mlx_params fdf)
{
	t_scaling_factor	scaling_factor;
	size_t	i;
	size_t	j;
	
	scaling_factor.horizontal = 1920 * 0.8 / frame_info.x_range;
	scaling_factor.vertical = 1920 * 0.8 / frame_info.y_range;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			mlx_pixel_put(fdf.mlx, fdf.win, (data_array[i][j].x - frame_info.min_x) * scaling_factor.horizontal + 192,
					(data_array[i][j].y - frame_info.min_y) * scaling_factor.vertical + 192, 0xFF00FF);
			j++;
		}
		i++;
	}
}

void	display_data(t_iso **data_array, t_dimensions map)
{
	t_mlx_params fdf;
	t_frame_info	frame_info;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1920, 1920, "Fil de Fer");
	fdf.img = mlx_new_image(fdf.mlx, 1920, 1920);
	get_frame_info(&frame_info, data_array, map);
	put_pixels(frame_info, data_array, map, fdf);
	mlx_loop(fdf. mlx);
}
