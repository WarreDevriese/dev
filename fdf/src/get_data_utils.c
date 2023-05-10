/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:56:03 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/09 16:51:33 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_dimensions(char	*file, t_dimensions *map)
{
	int		fd;
	char	*line;
	size_t	temp_width;

	map->width = 0;
	map->height = 0;
	ft_open_rdonly(file, &fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_width = ft_word_count(line, ' ');
		if (temp_width > map->width)
			map->width = temp_width;
		map->height++;
		free(line);
	}
	ft_close(fd);
}

void	get_frame_info(t_frame_info *frame_info, t_iso **data_array, t_dimensions map)
{
	int	i;
	int	j;
	
	i = 0;
	while ((size_t)i < map.height)
	{
		j = 0;
		while ((size_t)j < map.width)
		{
			if	((i == 0 && j == 0) || data_array[i][j].x < frame_info->min_x)
				frame_info->min_x = data_array[i][j].x;
			if	((i == 0 && j == 0) || data_array[i][j].x > frame_info->max_x)
				frame_info->max_x = data_array[i][j].x;
			if	((i == 0 && j == 0) || data_array[i][j].y < frame_info->min_y)
				frame_info->min_y = data_array[i][j].y;
			if	((i == 0 && j == 0) || data_array[i][j].y > frame_info->max_y)
				frame_info->max_y = data_array[i][j].y;
			j++;
		}
		i++;
	}
	frame_info->x_range = frame_info->max_x - frame_info->min_x;
	frame_info->y_range = frame_info->max_y - frame_info->min_y;
}
