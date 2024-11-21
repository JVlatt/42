/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:13:59 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/20 18:31:10 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	unsigned char	uc;

	if (!str)
		return (NULL);
	uc = (unsigned char)c;
	while (*str)
	{
		if (*str == uc)
			return (str);
		str++;
	}
	if (*str == uc)
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buffer[j])
		str[i++] = buffer[j++];
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
