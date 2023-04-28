/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/28 18:46:53 by wdevries         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_dimensions	dimensions;

	if (argc != 2)
	{
		perror("Usage: ./fdf <filename>");
		exit(1);
	}
	get_dimensions(argv[1], &dimensions);
	printf("Width: %i\n", (int)dimensions.width);
	printf("Height: %i\n", (int)dimensions.height);
	return (0);
}
