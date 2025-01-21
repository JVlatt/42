/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:31:19 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 11:31:53 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

t_vector	to_screen(double world_x, double world_y,
					double zoom, t_vector shift)
{
	t_vector	screen_position;
	double		normalized_x;
	double		normalized_y;

	normalized_x = (world_x - shift.x) * zoom;
	normalized_y = (world_y - shift.y) * zoom;
	screen_position.x = ((normalized_x + 2.0) / 4.0) * WDW_WIDTH;
	screen_position.y = ((2.0 - normalized_y) / 4.0) * WDW_HEIGHT;
	return (screen_position);
}
