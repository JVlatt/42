/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:03:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/22 16:28:31 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_handler(t_fractal *fractal)
{
	if (!fractal)
		return (1);
	if (fractal->mlx_connection)
	{
		mlx_loop_end(fractal->mlx_connection);
		if (fractal->img.img_ptr)
			mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		if (fractal->mlx_window)
			mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	if (fractal->color_map)
		free(fractal->color_map);
	exit (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift.x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift.x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift.y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift.y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_equal)
	{
		fractal->max_iteration += 10;
		if (fractal->max_iteration > 1000)
			fractal->max_iteration = 1000;
		update_color_map(fractal);
	}
	else if (keysym == 41 || keysym == XK_minus)
	{
		fractal->max_iteration -= 10;
		if (fractal->max_iteration < 0)
			fractal->max_iteration = 1;
		update_color_map(fractal);
	}
	else
		return (1);
	return (0);
}

int	mouse_btn_handler(int button, int x, int y, t_fractal *fractal)
{
	t_vector	newshift;
	t_vector	mouseWorldPos;
	
	mouseWorldPos = to_world(x, y, fractal->zoom, fractal->shift);
	if (button == Button1)
	{
		if (!ft_strcmp(fractal->name, "julia"))
		{
			if (fractal->mouse_mode == 0)
				fractal->mouse_mode = 1;
			else
				fractal->mouse_mode = 0;
		}	
	}
	else if (button == Button4)
	{
		fractal->zoom *= 0.95;
		newshift.x = (mouseWorldPos.x - fractal->shift.x) * (0.05);
		newshift.y = (mouseWorldPos.y - fractal->shift.y) * (0.05);
		fractal->shift.x += newshift.x;
		fractal->shift.y += newshift.y;
	}
	else if (button == Button5)
		fractal->zoom *= 1.05;
	return (0);
}

int	mouse_position_handler(int x, int y, t_fractal *fractal)
{
	t_vector	noshift;

	noshift.x = 0;
	noshift.y = 0;
	fractal->mouse_worldpos = to_world(x, y, 1, noshift);
	return (0);
}
