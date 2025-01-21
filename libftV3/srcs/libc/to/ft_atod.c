/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:28:09 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 19:30:58 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static double	get_left_part(const char *str, int *len)
{
	double		result;

	result = 0;
	while (*(str + *len) >= '0' && *(str + *len) <= '9')
	{
		result = result * 10 + *(str + *len) - 48;
		*len += 1;
	}
	return (result);
}

static double	get_right_part(const char *str)
{
	double		result;
	int			len;

	len = 0;
	result = 0;
	while (*(str + len) >= '0' && *(str + len) <= '9')
		len++;
	while (len--)
		result = result / 10 + (*(str + len) - 48);
	return (result / 10);
}

static int	get_sign(const char *str, int *len)
{
	int			sign;

	sign = 1;
	while (*(str + *len) != '\0' && ((*(str + *len) >= 9 && *(str + *len) <= 13)
			|| *(str + *len) == 32))
	{
		*len += 1;
	}
	if (*(str + *len) != '\0' && (*(str + *len) == '+' || *(str + *len) == '-'))
	{
		if (*(str + *len) == '-')
			sign *= -1;
		*len += 1;
	}
	return (sign);
}

double	ft_atod(const char *str)
{
	double	left;
	double	right;
	int		sign;
	int		left_len;

	right = 0;
	left_len = 0;
	sign = get_sign(str, &left_len);
	left = get_left_part(str, &left_len);
	if (left < 0)
	{
		sign *= -1;
		left *= -1;
	}
	if (*(str + left_len) == '.' || *(str + left_len) == ',')
	{
		left_len++;
		right = get_right_part((str + left_len));
	}
	return (sign * (left + right));
}
