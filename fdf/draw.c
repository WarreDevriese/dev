/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:23:31 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/16 14:44:34 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_mlx_params *mlx_params, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx_params->addr + (y * mlx_params->line_length + x * (mlx_params->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

static void	init_bresenham_params(t_iso point1, t_iso point2, t_bresenham_params *line)
{
	line->dx = ft_abs((int)round(point2.x) - (int)round(point1.x));
	line->dy = ft_abs((int)round(point2.y) - (int)round(point1.y));

	if (point1.x < point2.x)
		line->stepx = 1;
	else
		line->stepx = -1;
	if (point1.y < point2.y)
		line->stepy = 1;
	else
		line->stepy = -1;
	if (line->dx > line->dy)
		line->err = line->dx / 2;
	else
		line->err = -line->dy / 2;
}

static void	draw_line(t_iso point1, t_iso point2, t_mlx_params *mlx_params)
{
	t_bresenham_params	line;

	init_bresenham_params(point1, point2, &line);
	while (1)
	{
		set_pixel(mlx_params, (int)round(point1.x), (int)round(point1.y), 0xFFFFFF);//IMPLEMENT GET_COLOR FUNCTION
		if ((int)round(point1.x) == (int)round(point2.x)&& (int)round(point1.y) == (int)round(point2.y))
			break ;
		line.err2 = line.err;
		if (line.err2 > -line.dx)
		{
			line.err -= line.dy;
			point1.x += line.stepx;
		}
		if (line.err2 < line.dy)
		{
			line.err += line.dx;
			point1.y += line.stepy;
		}
	}
}

void	create_image(t_iso **data_array, t_mlx_params *mlx_params, t_dimensions map)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns)
		{
			if (j + 1 < map.columns)
				draw_line(data_array[i][j], data_array[i][j + 1], mlx_params);
			if (i + 1 < map.rows)
				draw_line(data_array[i][j], data_array[i + 1][j], mlx_params);
			j++;
		}
		i++;
	}
}
