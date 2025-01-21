/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:24 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 11:41:44 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	get_left_part(const char *str, int *len)
{
	double		result;
	int			sign;

	sign = 1;
	result = 0;
	while (*(str + *len) != '\0' && ((*(str + *len) >= 9 && *(str + *len) <= 13)
			|| *(str + *len) == 32))
	{
		*len += 1;
		printf("%c", *(str + *len));
	}
	if (*(str + *len) != '\0' && (*(str + *len) == '+' || *(str + *len) == '-'))
	{
		if (*(str + *len) == '-')
			sign *= -1;
		*len += 1;
	}
	while (*(str + *len) >= '0' && *(str + *len) <= '9')
	{
		result = result * 10 + *(str + *len) - 48;
		*len += 1;
	}
	return (sign * result);
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

double	ft_atod(const char *str)
{
	double	left;
	double	right;
	int		sign;
	int		left_len;

	sign = 1;
	right = 0;
	left_len = 0;
	left = get_left_part(str, &left_len);
	if (left < 0)
	{
		sign *= -1;
		left *= -1;
	}
	if (*(str + left_len) == '.')
	{
		left_len++;
		right = get_right_part((str + left_len));
	}
	return (sign * (left + right));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *) s1;
	cp2 = (unsigned char *) s2;
	while (*cp1 && *cp2)
	{
		if (*cp1 != *cp2)
			return (*cp1 - *cp2);
		cp1++;
		cp2++;
	}
	return (*cp1 - *cp2);
}
