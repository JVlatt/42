/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:15:48 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 11:42:03 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_frame(t_fractal *fractal)
{
	if (!fractal)
		return (1);
	fractal_render(fractal);
	return (0);
}

static int	parse_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc >= 2)
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
					return (1);
				}
			}
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
		perror("Error : Incorrect Arguments");
		return (1);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop_hook(fractal.mlx_connection, &render_frame, &fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
