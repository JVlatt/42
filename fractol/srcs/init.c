/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:51:14 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 20:05:58 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iteration = 42;
	fractal->shift.x = 0.0;
	fractal->shift.y = 0.0;
	fractal->zoom = 1.0;
	fractal->mouse_mode = 0;
	fractal->color_map = malloc(sizeof(int) * fractal->max_iteration);
}

void	update_color_map(t_fractal *fractal)
{
	int	i;

	free(fractal->color_map);
	fractal->color_map = malloc(sizeof(int) * fractal->max_iteration);
	if (!fractal->color_map)
	{
		ft_putstr_fd("Failed to allocate color map", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < fractal->max_iteration)
	{
		fractal->color_map[i] = color_interpolation(i, BLACK,
				WHITE, fractal->max_iteration);
		i++;
	}
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress,
		KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress,
		ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
}

static void	init_mlx_wdw_data(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
	{
		ft_putstr_fd("Failed to init mlx_connection", 2);
		exit(EXIT_FAILURE);
	}
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WDW_WIDTH, WDW_HEIGHT,
			fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_putstr_fd("Failed to init mlx (window)", 2);
		exit(EXIT_FAILURE);
	}
}

void	fractal_init(t_fractal *fractal)
{
	init_mlx_wdw_data(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WDW_WIDTH, WDW_HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection,
			fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_putstr_fd("Failed to init mlx (img_ptr)", 2);
		exit(EXIT_FAILURE);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	if (NULL == fractal->img.pixels_ptr)
	{
		close_handler(fractal);
		ft_putstr_fd("Failed to init mlx (get_data_addr)", 2);
		exit(EXIT_FAILURE);
	}
	data_init(fractal);
	events_init(fractal);
	update_color_map(fractal);
}
