/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/10 10:53:49 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	apply_scaling(t_frame_info frame_info, t_iso ***data_array, t_dimensions map)
{
	t_scaling_factor	scaling_factor;
	int	i;
	int	j;
	
	get_scaling_factor(frame_info, &scaling_factor);
	i = 0;
	while ((size_t)i < map.height)
	{
		j = 0;
		while ((size_t)j < map.width)
		{
			data_array[i][j]->scaled_x = (data_array[i][j]->x - frame_info.min_x)
				* scaling_factor.horizontal + (1920 / 2 - frame_info.x_range * scaling_factor.horizontal / 2);
			data_array[i][j]->scaled_y = (data_array[i][j]->y - frame_info.min_y)
				* scaling_factor.vertical + (1920 / 2 - frame_info.y_range * scaling_factor.vertical / 2);
			j++;
		}
		i++;
	}
}

static void		allocate_data_array(size_t width, size_t height, t_iso ***data_array)
{
	size_t	i;

	*data_array = (t_iso **)malloc((height) * sizeof(t_iso *));
	if (!*data_array)
	{
		perror("Error malloc data_array");
		exit(1);
	}
	i = 0;
	while (i < height)
	{
		(*data_array)[i] = (t_iso *)malloc(width * sizeof(t_iso));
		if (!(*data_array)[i])
		{
			while (i)
				free((*data_array)[--i]);
			free(*data_array);
			perror("Error malloc data_array");
			exit(1);
		}
		i++;
	}
}

static void		populate_data_array(int fd, t_dimensions map, t_math angle_values, t_iso ***data_array)
{
	int		row;
	int		column;
	char	*line;
	char	**words;

	row = 0;
	while ((size_t)row < map.height)
	{
		line = get_next_line(fd);
		words = ft_split(line, ' ');
		column = 0;
		while ((size_t)column < map.width)
		{
			(*data_array)[row][column].z = ft_atoi(words[column]);
			(*data_array)[row][column].x = (column - row) * angle_values.cos30;
			(*data_array)[row][column].y = (column + row) * angle_values.sin30 - (*data_array)[row][column].z;
			free(words[column]);
			column++;
		}
		free(line);
		free(words);
		row++;
	}
}

t_iso		**get_data(char *file, t_dimensions *map)
{
	int		fd;
	t_iso	**data_array;
	t_math	angle_values;

	get_dimensions(file, map);
	allocate_data_array(map->width, map->height, &data_array);
	ft_open_rdonly(file, &fd);
	angle_values.sin30 = sin(M_PI / 6);
	angle_values.cos30 = cos(M_PI / 6);
	populate_data_array(fd, *map, angle_values, &data_array);
	ft_close(fd);
	return (data_array);
}
