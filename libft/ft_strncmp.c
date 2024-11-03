/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:53:02 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/03 22:06:03 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *) s1;
	cp2 = (unsigned char *) s2;
	i = 0;
	while (cp1[i] && cp2[i] && i < n)
	{
		if (cp1[i] != cp2[i])
		{
			return (cp1[i] - cp2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return (cp1[i] - cp2[i]);
}
