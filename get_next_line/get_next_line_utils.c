/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:13:59 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/19 18:16:26 by mmanuell         ###   ########.fr       */
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
/*
char	*ft_strtrim(char *src, int start, int end)
{
	int		i;
	int		j;
	char	*dup;
	size_t	size;

	if (!src)
		return (NULL);
	size = end - start;
	dup = ft_calloc(size + 1, sizeof(char));
	if (!dup)
		return (NULL);
	j = start;
	i = 0;
	while (src[j] && j < end)
	{
		dup[i] = src[j];
		i++;
		j++;
	}
	dup[i] = '\0';
	return (dup);
}*/

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!stash || !buffer)
		return (NULL);
	str = ft_calloc(ft_strlen(stash) + ft_strlen(buffer) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (stash[i])
		while (stash[i])
		{
			str[i] = stash[i];
			i++;
		}
	while (buffer[j])
	{
		str[i++] = buffer[j++];
	}
	str[i] = 0;
	free(stash);
	free(buffer);
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
	while (n--)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
