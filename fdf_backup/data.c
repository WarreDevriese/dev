/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/06/30 12:30:33 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_dimensions(char	*file, t_dimensions *map)
{
	int		fd;
	char	*line;
	int		temp_columns;

	map->columns = 0;
	map->rows = 0;
	ft_open_rdonly(file, &fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_columns = ft_word_count(line, ' ');
		if (temp_columns > map->columns)
			map->columns = temp_columns;
		map->rows++;
		free(line);
	}
	ft_close(fd);
}

static void		allocate_data_array(int columns, int rows, t_iso ***data_array)
{
	int	i;

	*data_array = (t_iso **)malloc((rows) * sizeof(t_iso *));
	if (!*data_array)
	{
		perror("Error malloc data_array");
		exit(1);
	}
	i = 0;
	while (i < rows)
	{
		(*data_array)[i] = (t_iso *)malloc(columns * sizeof(t_iso));
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
	while (row < map.rows)
	{
		line = get_next_line(fd);
		words = ft_split(line, ' ');
		column = 0;
		while (column < map.columns)
		{
			(*data_array)[row][column].z = ft_atoi(words[column]);
			(*data_array)[row][column].unscaled_x = (column - row) * angle_values.cos30;
			(*data_array)[row][column].unscaled_y = (column + row) * angle_values.sin30 - (*data_array)[row][column].z;
			free(words[column]);
			column++;
		}
		free(line);
		free(words);
		row++;
	}
}

void	get_data(char *file, t_iso ***data_array, t_dimensions *map)
{
	int		fd;
	t_math	angle_values;

	get_dimensions(file, map);
	allocate_data_array(map->columns, map->rows, data_array);
	ft_open_rdonly(file, &fd);
	angle_values.sin30 = sin(M_PI / 6);
	angle_values.cos30 = cos(M_PI / 6);
	populate_data_array(fd, *map, angle_values, data_array);
	ft_close(fd);
}
