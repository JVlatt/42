/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:31:28 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/20 14:19:15 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_pixel_put(t_vector coords, t_img *img, int color)
{
	int	offset;

	offset = (coords.y * img->line_len)
		+ (coords.x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	select_fractal(t_vector *z, t_vector *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->c_value.x;
		c->y = fractal->c_value.y;
	}
	else if (!ft_strcmp(fractal->name, "burning_ship"))
	{
		c->x = z->x;
		c->y = z->y;
		z->x = ft_fabs(z->x);
		z->y = ft_fabs(z->y);
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	pixel_render(t_vector coords, t_vector start,
			t_vector step, t_fractal *fractal)
{
	t_vector	z;
	t_vector	c;
	int			i;

	i = 0;
	z.x = start.x + (coords.x * step.x);
	z.y = start.y - (coords.y * step.y);
	select_fractal(&z, &c, fractal);
	while (i < fractal->max_iteration)
	{
		if (!ft_strcmp(fractal->name, "burning_ship"))
		{
			z.x = ft_fabs(z.x);
			z.y = ft_fabs(z.y);
		}
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			ft_pixel_put(coords, &fractal->img, fractal->color_map[i]);
			return ;
		}
		i++;
	}
	ft_pixel_put(coords, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	t_vector	start;
	t_vector	step;
	t_vector	screen;

	if (!fractal)
		return ;
	start = to_world(0, 0, fractal->zoom, fractal->shift);
	step.x = (4.0 * fractal->zoom) / WDW_WIDTH;
	step.y = (4.0 * fractal->zoom) / WDW_HEIGHT;
	screen.y = -1;
	while (++screen.y < WDW_HEIGHT)
	{
		screen.x = -1;
		while (++screen.x < WDW_WIDTH)
		{
			pixel_render(screen, start, step, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
