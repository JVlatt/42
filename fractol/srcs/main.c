/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:15:48 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 20:08:45 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	render_frame(t_fractal *fractal)
{
	if (!fractal)
		return (1);
	if (fractal->mouse_mode == 1)
	{
		fractal->c_value.x = fractal->mouse_worldpos.x;
		fractal->c_value.y = fractal->mouse_worldpos.y;
	}
	fractal_render(fractal);
	return (0);
}

static int	parse_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc >= 2 && argc <= 4)
	{
		if (!ft_strcmp("mandelbrot", argv[1]) || !ft_strcmp("julia", argv[1])
			|| !ft_strcmp("burning_ship", argv[1]))
		{
			fractal->name = argv[1];
			if (!ft_strcmp("julia", argv[1]))
			{
				if (argc == 4)
				{
					fractal->c_value.x = ft_atod(argv[2]);
					fractal->c_value.y = ft_atod(argv[3]);
				}
				else
				{
					fractal->c_value.x = -0.8;
					fractal->c_value.y = 0.156;
				}
			}
			else if (argc != 2)
				return (0);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!parse_args(argc, argv, &fractal))
	{
		ft_putstr_fd("Error : Incorrect Arguments\n", 2);
		ft_putstr_fd("./fract-ol <type> <if julia : c> <if julia : i> \n", 2);
		ft_putstr_fd("Types : mandelbrot, julia, burning_ship\n", 2);
		return (1);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop_hook(fractal.mlx_connection, &render_frame, &fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
