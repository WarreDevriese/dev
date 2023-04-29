/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:17 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/29 15:48:46 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_map
{
	size_t	width;
	size_t	height;
}				t_map;

typedef struct s_mlx_params
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_mlx_params;

typedef struct	s_iso
{
	size_t		width;
	size_t		height;
	size_t		ratio;
}				t_iso;

void		parse_map(char *file, int ***data);
int			main(int argc, char **argv);
void		initialize_window(void);

#endif
