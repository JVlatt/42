
#include "fractol.h"

int render_frame(t_fractal* fractal)
{
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
	mlx_loop_hook(fractal.mlx_connection, render_frame, &fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);	
}