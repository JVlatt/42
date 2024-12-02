#include "fractol.h"

int close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	if (fractal->color_map)
        free(fractal->color_map);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += 0.5;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.5;
	else if (keysym == XK_plus || keysym == XK_equal)
	{
		fractal->max_iteration += 10;
		init_color_map(fractal); 
	}
	else if (keysym == 41 || keysym == XK_minus)
	{
		fractal->max_iteration -= 10;
		init_color_map(fractal);
	}	 
	else
	{
		printf("Unhandeld keysym : %d \n", keysym);
		return (1);
	}
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	else
	{
		printf("Unhandeld mouse btn : %d \n", button);
		return (1);
	}
	fractal_render(fractal);
	return (0);
}