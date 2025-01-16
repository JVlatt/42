/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:39:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/16 17:35:55 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	color_interpolation(double unscaled_num, double new_min, 
							double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

t_vector	to_world(int screen_x, int screen_y, double zoom, t_vector shift)
{
	t_vector	world_position;
	double		normalized_x;
    double		normalized_y;
	
	normalized_x = ((double)screen_x / WDW_WIDTH) * 4.0 - 2.0;
    normalized_y = 2.0 - ((double)screen_y / WDW_HEIGHT) * 4.0;
    world_position.x = normalized_x * zoom + shift.x;
    world_position.y = normalized_y * zoom + shift.y;
	return (world_position);
}

t_vector	to_screen(double world_x, double world_y, double zoom, t_vector shift)
{
	t_vector screen_position;
    double normalized_x;
    double normalized_y;
	
	normalized_x = (world_x - shift.x) * zoom;
    normalized_y = (world_y - shift.y) * zoom;
    screen_position.x = ((normalized_x + 2.0) / 4.0) * WDW_WIDTH;
    screen_position.y = ((2.0 - normalized_y) / 4.0) * WDW_HEIGHT;
    return screen_position;
}

t_vector	sum_complex(t_vector z1, t_vector z2)
{
	t_vector	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_vector	square_complex(t_vector z)
{
	t_vector	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result); 
}