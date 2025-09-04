/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:12:39 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/12 17:50:15 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destcpy;
	char	*srccpy;
	int		i;

	if (!dest && !src)
		return (NULL);
	destcpy = (char *) dest;
	srccpy = (char *) src;
	i = 0;
	if (dest <= src)
	{
		while (n--)
			*destcpy++ = *srccpy++;
	}
	else if (dest > src)
	{
		i = n - 1;
		while (i >= 0)
		{
			destcpy[i] = srccpy[i];
			i--;
		}
	}
	return (dest);
}
