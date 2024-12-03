/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:51:14 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/02 18:21:06 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iteration = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	init_color_map(t_fractal *fractal) 
{
    if (fractal->color_map)
        free(fractal->color_map);
    fractal->color_map = malloc(sizeof(int) * fractal->max_iteration);
    if (!fractal->color_map) {
        perror("Failed to allocate color map");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < fractal->max_iteration; i++) {
        fractal->color_map[i] = linear_interpolation(i, BLACK, WHITE, 0, fractal->max_iteration);
    }
}
static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		return ;
	fractal->mlx_window
		= mlx_new_window(fractal->mlx_connection,
			WDW_WIDTH, WDW_HEIGHT,
			"mandelbrot");
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		return ;
	}
	fractal->img.img_ptr
		= mlx_new_image(fractal->mlx_connection,
			WDW_WIDTH,
			WDW_HEIGHT);
	if (NULL == fractal->img.img_ptr)
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
	events_init(fractal);
	init_color_map(fractal);
}