/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:31:28 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/29 18:31:39 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static	void ft_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
static void	pixel_render(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	
	i = 0;
	z.x = 0.0;
	z.y = 0.0;

	c.x = linear_interpolation(x, -2, 2, 0, WDW_WIDTH);
	c.y = linear_interpolation(y, 2, -2, 0, WDW_HEIGHT);

	while (i < fractal->max_iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = linear_interpolation(i, BLACK, WHITE, 0, fractal->max_iteration);
			ft_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(x, y, &fractal->img, NEON_ORANGE);
}
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < WDW_HEIGHT)
	{
		x = -1;
		while(++x < WDW_WIDTH)
		{
			pixel_render(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}