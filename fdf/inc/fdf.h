/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:17 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/10 10:36:55 by warredevriese    ###   ########.fr       */
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
# include "../libft/inc/libft.h"

typedef struct	s_dimensions
{
	size_t	width;
	size_t	height;
}				t_dimensions;

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
	double	x;
	double	y;
	double	z;
	double	scaled_x;
	double	scaled_y;
}				t_iso;

typedef struct	s_math
{
	double	sin30;
	double	cos30;
}				t_math;

typedef struct	s_frame_info
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	x_range;
	double	y_range;
}				t_frame_info;

typedef struct	s_scaling_factor
{
	double	horizontal;
	double	vertical;
	double	ratio;
}				t_scaling_factor;

t_iso		**get_data(char *file, t_dimensions *map);
int			main(int argc, char **argv);
void		display_data(void);
void 		free_data_array(t_iso ***data_array, size_t height);
void 		close_hook(t_mlx_params *fdf, t_iso ***data_array, size_t height);
void    	apply_scaling(t_frame_info frame_info, t_iso ***data_array, t_dimensions map);
void    	get_frame_info(t_frame_info *frame_info, t_iso **data_array, t_dimensions map);
void    	get_dimensions(char *file, t_dimensions *map);

#endif
