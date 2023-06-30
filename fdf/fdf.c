/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:15:57 by warredevrie       #+#    #+#             */
/*   Updated: 2023/06/30 12:04:52 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx_params init_mlx_params()
{
    t_mlx_params    params;

    params.mlx = mlx_init();
    params.win = mlx_new_window(params.mlx, 1920, 1920, "Fil de Fer");
    params.img = mlx_new_image(params.mlx, 1920, 1920);
    params.addr = mlx_get_data_addr(params.img, &params.bits_per_pixel, &params.line_length, &params.endian);
    return (params);
}

int main(int argc, char **argv)
{
    t_iso       **data_array;
    t_dimensions    map;
    t_fdf_params fdf;

    (void)argc;
	//add error handling
    get_data(argv[1], &data_array, &map);
    apply_scaling(&data_array, map);
	fdf.mlx_params = init_mlx_params();
	create_image(data_array, &fdf.mlx_params, map);
	mlx_put_image_to_window(fdf.mlx_params.mlx, fdf.mlx_params.win, fdf.mlx_params.img, 0, 0);
	handle_hooks(data_array, map, fdf.mlx_params);
    mlx_loop(fdf.mlx_params.mlx);
    return (0);
}
