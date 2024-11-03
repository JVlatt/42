/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:24:32 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/03 22:29:28 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1size;
	size_t	s2size;

	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	str = malloc(sizeof (char) * (s1size + s2size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1size);
	ft_strlcat(str, s2, s1size + s2size + 1);
	return (str);
}
