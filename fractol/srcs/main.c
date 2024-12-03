
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	(void) argv;
	(void) argc;
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);	
}