/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:53:02 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/12 17:50:59 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (str[i] && i < len)
	{
		if (str[i] == *to_find)
		{
			while (str[i + j] == to_find[j] && i + j < len)
			{
				if (!to_find[j + 1])
					return ((char *)&str[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
