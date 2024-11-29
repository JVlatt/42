/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:51:14 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/29 18:29:13 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iteration = 42;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		return ;
	fractal->mlx_window
		= mlx_new_window(fractal->mlx_connection,
			WDW_WIDTH, WDW_HEIGHT,
			fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		return ;
	}
	fractal->img.img_ptr
		= mlx_new_image(fractal->mlx_connection,
			WDW_WIDTH,
			WDW_HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection,
			fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		return;
	}
	fractal->img.pixels_ptr
		= mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
}