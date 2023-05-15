/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:17 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/15 09:53:26 by wdevries         ###   ########.fr       */
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
	size_t			width;
	size_t			height;
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
	double			x;
	double			y;
	double			z;
	double			scaled_x;
	double			scaled_y;
}					t_iso;

typedef struct s_math
{
	double			sin30;
	double			cos30;
}					t_math;

typedef struct s_frame_info
{
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			x_range;
	double			y_range;
}					t_frame_info;

typedef struct s_scaling_factor
{
	double			horizontal;
	double			vertical;
	double			ratio;
}					t_scaling_factor;

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
t_mlx_params		init_mlx_params(t_fdf_params fdf);

#endif
