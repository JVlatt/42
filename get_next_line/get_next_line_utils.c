/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:13:59 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/13 16:47:40 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strchr_index(char *str, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	if (!str || !*str)
		return (-1);
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

size_t	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(char *src, size_t size)
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
//	free(src);
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
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
	free(s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		i;
	size_t	n;

	i = 0;
	n = nmemb * size;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	while(n--)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
