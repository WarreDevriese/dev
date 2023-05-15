/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warredevriese <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:15:57 by warredevriese     #+#    #+#             */
/*   Updated: 2023/05/10 19:22:44 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_iso       **data_array;
    t_dimensions    map;
	t_mlx_params	mlx_params;
    t_fdf_params fdf;

    (void)argc;
	//add error handling
    get_data(argv[1], &data_array, &map);
    apply_scaling(&data_array, map);
    mlx_params.mlx = mlx_init();
    mlx_params.win = mlx_new_window(mlx_params.mlx, 1920, 1920, "Fil de Fer");
    mlx_params.img = mlx_new_image(mlx_params.mlx, 1920, 1920);
	mlx_params.addr = mlx_get_data_addr(mlx_params.img, &mlx_params.bits_per_pixel, &mlx_params.line_length, &mlx_params.endian);
	//add drawing lines
	mlx_put_image_to_window(mlx_params.mlx, mlx_params.win, mlx_params.img, 0, 0);
	handle_hooks(data_array, map, mlx_params);
    mlx_loop(fdf.mlx_params.mlx);
    return (0);
}
