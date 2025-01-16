/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:15:48 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/16 18:16:42 by mmanuell         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	(void) argv;
	(void) argc;
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop_hook(fractal.mlx_connection, &render_frame, &fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
