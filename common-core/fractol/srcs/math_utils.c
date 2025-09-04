/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:39:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 19:51:42 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	color_interpolation(double unscaled_num, double new_min,
							double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
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

double	ft_fabs(double value)
{
	int	sign;

	sign = 1;
	if (value < 0)
		sign = -1;
	return (value * sign);
}
