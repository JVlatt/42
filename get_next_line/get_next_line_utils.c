/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:13:59 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/13 10:49:55 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strchr_index(const char *str, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	uc = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == uc)
			return (i);
		i++;
	}
	if (str[i] == uc)
		return (i);
	else
		return (-1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(const char *src, size_t size)
{
	unsigned int	i;
	char			*dup;

	i = 0;
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	while (src[i] && i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

void	*ft_calloc_bzero(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;

	n = nmemb * size;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	while(n--)
	{
		*((char *)(ptr)) = 0;
		ptr++;
	}
	return (ptr);
}
