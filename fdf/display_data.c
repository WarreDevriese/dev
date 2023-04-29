/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:09:34 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/29 15:36:28 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_window(void)
{
	t_mlx_params fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1080, 1080, "Fil de Fer");
	fdf.img = mlx_new_image(fdf.mlx, 1080, 1080);
	mlx_loop(fdf. mlx);
}
