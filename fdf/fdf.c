/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/28 19:47:22 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_dimensions(char	*file, t_dimensions *dimensions)
{
	int		fd;
	char	*line;
	size_t	temp_width;

	dimensions->width = 0;
	dimensions->height = 0;
	ft_open_rdonly(file, &fd);
	while (1)
	{
		line = get_next_line(fd);
		//add error handle. errno?
		if (!line)
			break ;
		temp_width = ft_word_count(line, ' ');
		if (temp_width > dimensions->width)
			dimensions->width = temp_width;
		dimensions->height++;
		free(line);
	}
	ft_close(fd);
}

int		**allocate_2d_array(size_t width, size_t height)
{
	int		**data;
	size_t	i;

	data = (int **)malloc(height * sizeof(int *));
	if (!data)
	{
		perror("Error malloc 2D array");
		exit(1);
	}
	i = 0;
	while (i < height)
	{
		data[i] = (int *)malloc(width * sizeof(int));
		if (!data[i])
		{
			while (i)
				free(data[i--]);
			free(data);
			perror("Error malloc 2D array");
			exit(1);
		}
	}
	return (data);
}

int		**parse_map(file, dimensions)
{
	int		**data;
	int		fd;
	size_t	i;

	data = allocate_2d_array(dimensions.widthm dimensions.height);
	ft_open_rdonly(file, &fd);
	i = 0;
	while (i < dimensions.height)
	{

	}
	ft_close(fd);
	return (data);
}

int		main(int argc, char **argv)
{
	t_dimensions	dimensions;

	//add error handling for input
	(void)argc;
	get_dimensions(argv[1], &dimensions);
	return (0);
}
