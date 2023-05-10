/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:09:34 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/09 16:39:45 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_data(void)
{
	t_mlx_params fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1920, 1920, "Fil de Fer");
	fdf.img = mlx_new_image(fdf.mlx, 1920, 1920);
	mlx_loop(fdf. mlx);
}
