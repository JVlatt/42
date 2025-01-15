#include "fractol.h"

int close_handler(t_fractal *fractal)
{
	//mettre des verif
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
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_equal)
	{
		fractal->max_iteration += 10;
		update_color_map(fractal); 
	}
	else if (keysym == 41 || keysym == XK_minus)
	{
		fractal->max_iteration -= 10;
		update_color_map(fractal);
	}	 
	else
	{
		printf("Unhandeld keysym : %d \n", keysym);
		return (1);
	}
	//fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	static int oldX;
	static int oldY;
	if (button == Button4)
	{
		printf("Zoom In {%d,%d}\n", x , y);
		fractal->zoom *= 0.95;
		printf("Shift X to %f\n", linear_interpolation(x,-2 ,2, 0, WDW_WIDTH));
		printf("Shift Y to %f\n", linear_interpolation(y, 2 ,-2, 0, WDW_HEIGHT));
		if(x != oldX)
		{
			fractal->shift_x += linear_interpolation(x,-2 ,2, 0, WDW_WIDTH) * fractal->zoom;
			oldX = x;
		}
		if (y != oldY)
		{
			fractal->shift_y += linear_interpolation(y, 2 ,-2, 0, WDW_HEIGHT) * fractal->zoom;
			oldY = y;
		}
	}
	else if (button == Button5)
	{
		printf("Zoom Out {%d,%d}\n", x , y);
		fractal->zoom *= 1.05;
		//fractal->shift_x = linear_interpolation(x,-2 ,2, 0, WDW_WIDTH) * fractal->zoom;
		//fractal->shift_y = linear_interpolation(y,-2 ,2, 0, WDW_HEIGHT) * fractal->zoom;
	}
	else
	{
		printf("Unhandeld mouse btn : %d \n", button);
		return (1);
	}
	return (0);
}