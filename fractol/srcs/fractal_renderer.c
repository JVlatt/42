/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:31:28 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/02 18:41:38 by mmanuell         ###   ########.fr       */
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
	//int			color;
	
	i = 0;
	//printf("C START X = %f\n C START Y = %f\n C STEP X = %f\n C STEP Y = %f\n ", fractal->c_start.x, fractal->c_start.y, fractal->c_step.x, fractal->c_step.y);

	z.x = 0.0;
	z.y = 0.0;
	
	c.x = fractal->c_start.x + (x * fractal->c_step.x);
	c.y = fractal->c_start.y - (y * fractal->c_step.y);
	//printf("Rendering Pixel: x = %d, y = %d, c.x = %f, c.y = %f\n", x, y, c.x, c.y);
	while (i < fractal->max_iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			ft_pixel_put(x, y, &fractal->img, fractal->color_map[i]);
			//printf ("Putting color %d at index %d in coordinates {%d,%d} \n", fractal->color_map[i], i, x, y);
			return ;
		}
		i++;
	}
	ft_pixel_put(x, y, &fractal->img, WHITE);
}
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	fractal->c_start.x = (linear_interpolation(0, -2, 2, 0, WDW_WIDTH) * fractal->zoom) + fractal->shift_x;
    fractal->c_start.y = (linear_interpolation(0, 2, -2, 0, WDW_HEIGHT) * fractal->zoom) + fractal->shift_y;
	//fractal->c_start.x = fractal->shift_x + (-2 * fractal->zoom);
    //fractal->c_start.y = fractal->shift_y + (2 * fractal->zoom);
    fractal->c_step.x = (4.0 * fractal->zoom) / WDW_WIDTH;
    fractal->c_step.y = (4.0 * fractal->zoom) / WDW_HEIGHT;
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