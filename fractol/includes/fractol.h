/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:49:32 by matt              #+#    #+#             */
/*   Updated: 2025/01/21 11:45:04 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WDW_WIDTH
#  define WDW_WIDTH 800
# endif

# ifndef WDW_HEIGHT
#  define WDW_HEIGHT 800
# endif

// Define basic colors (RGB) and black/white
# define BLACK           0x000000 // Black (R=0, G=0, B=0)
# define WHITE           0xFFFFFF // White (R=255, G=255, B=255)
# define RED             0xFF0000 // Red (R=255, G=0, B=0)
# define GREEN           0x00FF00 // Green (R=0, G=255, B=0)
# define BLUE            0x0000FF // Blue (R=0, G=0, B=255)
# define YELLOW          0xFFFF00 // Yellow (R=255, G=255, B=0)
# define CYAN            0x00FFFF // Cyan (R=0, G=255, B=255)
# define MAGENTA         0xFF00FF // Magenta (R=255, G=0, B=255)
# define GRAY            0x808080 // Gray (R=128, G=128, B=128)

// Define psychedelic colors
# define NEON_PINK       0xFF007F // Neon Pink (R=255, G=0, B=127)
# define ELECTRIC_LIME   0x7FFF00 // Electric Lime (R=127, G=255, B=0)
# define ELECTRIC_CYAN   0x00FFFF // Electric Cyan (R=0, G=255, B=255)
# define VIVID_MAGENTA   0xFF00FF // Vivid Magenta (R=255, G=0, B=255)
# define SPRING_GREEN    0x00FF7F // Spring Green (R=0, G=255, B=127)
# define AMBER           0xFFBF00 // Amber (R=255, G=191, B=0)
# define HOT_PINK        0xFF69B4 // Hot Pink (R=255, G=105, B=180)
# define BLUE_VIOLET     0x8A2BE2 // Blue Violet (R=138, G=43, B=226)
# define NEON_ORANGE     0xFF4500 // Neon Orange (R=255, G=69, B=0)
# define ELECTRIC_PURPLE 0x7F00FF // Electric Purple (R=127, G=0, B=255)
# define NEON_GREEN      0x39FF14 // Neon Green (R=57, G=255, B=20)
# define DEEP_PINK       0xFF1493 // Deep Pink (R=255, G=20, B=147)
# define ACID_YELLOW     0xFFFF33 // Acid Yellow (R=255, G=255, B=51)
# define TURQUOISE       0x40E0D0 // Turquoise (R=64, G=224, B=208)

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp; // bytes per pixel
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_vector
{
	double	x; //real
	double	y; //i
}	t_vector;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	int			*color_map;
	double		escape_value;
	int			max_iteration;
	t_vector	shift;
	double		zoom;
	t_vector	c_value;
}	t_fractal;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

//		Events
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
void		update_color_map(t_fractal *fractal);

//		Maths
t_vector	sum_complex(t_vector z1, t_vector z2);
t_vector	square_complex(t_vector z);
double		color_interpolation(double unscaled_num, double new_min,
				double new_max, double old_max);
double		ft_fabs(double value);

//		Str
double		ft_atod(const char *str);
int			ft_strcmp(const char *s1, const char *s2);

//		Coords
t_vector	to_world(int screen_x, int screen_y, double zoom, t_vector shift);
t_vector	to_screen(double world_x, double world_y,
				double zoom, t_vector shift);

#endif