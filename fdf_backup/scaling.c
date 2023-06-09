/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:56:03 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/16 16:19:41 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_frame_info(t_frame_info *frame_info, t_iso **data_array, t_dimensions map)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns)
		{
			if	((i == 0 && j == 0) || data_array[i][j].unscaled_x < frame_info->min_x)
				frame_info->min_x = data_array[i][j].unscaled_x;
			if	((i == 0 && j == 0) || data_array[i][j].unscaled_x > frame_info->max_x)
				frame_info->max_x = data_array[i][j].unscaled_x;
			if	((i == 0 && j == 0) || data_array[i][j].unscaled_y < frame_info->min_y)
				frame_info->min_y = data_array[i][j].unscaled_y;
			if	((i == 0 && j == 0) || data_array[i][j].unscaled_y > frame_info->max_y)
				frame_info->max_y = data_array[i][j].unscaled_y;
			j++;
		}
		i++;
	}
	frame_info->x_range = frame_info->max_x - frame_info->min_x;
	frame_info->y_range = frame_info->max_y - frame_info->min_y;
}

/*
static void	get_scaling_factor(t_frame_info frame_info, t_scaling_factor *scaling_factor)
{
		scaling_factor->vertical = 1920 * 0.8 / frame_info.y_range;
		scaling_factor->horizontal = 1920 * 0.8 / frame_info.x_range;
}
*/

static void	get_scaling_factor(t_frame_info frame_info, t_scaling_factor *scaling_factor)
{
	scaling_factor->ratio = frame_info.x_range / frame_info.y_range;
	if (scaling_factor->ratio > 1)
	{
		scaling_factor->horizontal = 1920 * 0.8 / frame_info.x_range;
		scaling_factor->vertical = (1920 * 0.8 / frame_info.x_range) / scaling_factor->ratio;
	}
	else
	{
		scaling_factor->horizontal = (1920 * 0.8 / frame_info.y_range) * scaling_factor->ratio;
		scaling_factor->vertical = 1920 * 0.8 / frame_info.y_range;
	}
}

void	apply_scaling(t_iso ***data_array, t_dimensions map)
{
	t_frame_info		frame_info;
	t_scaling_factor	scaling_factor;
	int	i;
	int	j;
	
	get_frame_info(&frame_info, *data_array, map);
	get_scaling_factor(frame_info, &scaling_factor);
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns)
		{
			(*data_array)[i][j].x = ((*data_array)[i][j].unscaled_x - frame_info.min_x)
				* scaling_factor.horizontal + (1920 / 2 - frame_info.x_range * scaling_factor.horizontal / 2);
			(*data_array)[i][j].y = ((*data_array)[i][j].unscaled_y - frame_info.min_y)
				* scaling_factor.vertical + (1920 / 2 - frame_info.y_range * scaling_factor.vertical / 2);
			j++;
		}
		i++;
	}}
