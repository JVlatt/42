/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:37:15 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/22 12:19:26 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_is_str_ascii(const char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isascii(*str))
			return (0);
		str++;
	}
	return (1);
}
