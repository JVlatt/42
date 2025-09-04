/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:34 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/22 12:33:49 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_isnbr(const char *str, int space, int sign)
{
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == 32))
	{
		if (!space)
			return (0);
		str++;
	}
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (!sign)
			return (0);
		str++;
	}
	if (!*str)
		return (1);
	if (ft_strlen(str) > 11)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		str++;
	}
	if (!*str)
		return (1);
}
