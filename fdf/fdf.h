/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:17 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/16 12:17:08 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_dimensions
{
	int				width;
	int				height;
}					t_dimensions;

typedef struct s_mlx_params
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx_params;

typedef struct s_iso
{
	float			unscaled_x;
	float			unscaled_y;
	float			x;
	float			y;
	float			z;
}					t_iso;

typedef struct s_math
{
	float			sin30;
	float			cos30;
}					t_math;

typedef struct s_frame_info
{
	float			min_x;
	float			max_x;
	float			min_y;
	float			max_y;
	float			x_range;
	float			y_range;
}					t_frame_info;

typedef struct s_scaling_factor
{
	float			horizontal;
	float			vertical;
	float			ratio;
}					t_scaling_factor;

typedef struct	s_bresenham_params
{
	int				dx;
	int				dy;
	int				stepx;
	int				stepy;
	int				err;
	int				err2;
}				t_bresenham_params;

typedef struct s_fdf_params
{
	t_mlx_params	mlx_params;
	t_dimensions	map;
	t_iso			**data_array;
}					t_fdf_params;

int					main(int argc, char **argv);
void				get_data(char *file, t_iso ***data_array,
						t_dimensions *map);
void				close_hook(t_mlx_params *fdf, t_iso ***data_array,
						size_t height);
void				apply_scaling(t_iso ***data_array, t_dimensions map);
void				handle_hooks(t_iso **data_array, t_dimensions map,
						t_mlx_params mlx_params);
void				create_image(t_iso **data_array, t_mlx_params *mlx_params, t_dimensions map);

#endif
