/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:00 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/10 19:05:00 by warredevriese    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void free_data_array(t_iso ***data_array, size_t height)
{
    size_t i;

    i = 0;
    while (i < height)
        free((*data_array)[i++]);
    free(*data_array);
    printf("%s\n", "Data successfully freed");
}

static int keypress_hook(int keycode, void *param)
{
    t_fdf_params *params = (t_fdf_params *)param;
    if (keycode == 65307)
    {
        free_data_array(&(params->data_array), params->map.height);
        mlx_destroy_window(params->mlx_params.mlx, params->mlx_params.win);
        exit(0);
    }
    return (0);
}

static int destroy_hook(t_fdf_params *params)
{
    free_data_array(&(params->data_array), params->map.height);
    mlx_destroy_window(params->mlx_params.mlx, params->mlx_params.win);
    exit(0);
    return (0);
}

int main(int argc, char **argv)
{
    t_iso       **data_array;
    t_dimensions    map;
	t_mlx_params	mlx_params;
    t_fdf_params fdf;

    (void)argc;
    get_data(argv[1], &data_array, &map);
    apply_scaling(&data_array, map);
    mlx_params.mlx = mlx_init();
    mlx_params.win = mlx_new_window(mlx_params.mlx, 1920, 1920, "Fil de Fer");
    mlx_params.img = mlx_new_image(mlx_params.mlx, 1920, 1920);
	mlx_params.addr = mlx_get_data_addr(mlx_params.img, &mlx_params.bits_per_pixel, &mlx_params.line_length, &mlx_params.endian);
	mlx_put_image_to_window(mlx_params.mlx, mlx_params.win, mlx_params.img, 0, 0);
    fdf.data_array = data_array;
    fdf.map = map;
	fdf.mlx_params = mlx_params;
    mlx_hook(fdf.mlx_params.win, 2, 1L<<0, keypress_hook, &fdf);
    mlx_hook(fdf.mlx_params.win, 17, 0, destroy_hook, &fdf);
    mlx_loop(fdf.mlx_params.mlx);
    return (0);
}
