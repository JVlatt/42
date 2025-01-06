/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:38:36 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/12 19:27:00 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static char	*extract_line(char *stash)
{
	int		i;
	char	*out;
	int		len;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	len = i;
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = stash[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

static char	*get_remaining_buffer(char *stash)
{
	int		i;
	int		j;
	char	*out;
	int		len;

	len = 0;
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	len = ft_strlen(stash + i);
	if (len == 0)
	{
		free(stash);
		return (NULL);
	}
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (j < len)
		out[j++] = stash[i++];
	free(stash);
	return (out);
}

static char	*read_to_next_line(int fd, char *stash)
{
	char	*buffer;
	int		len;

	len = 1;
	while (len > 0 && !ft_strchr(stash, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (len == 0)
		{
			free(buffer);
			return (stash);
		}
		buffer[len] = 0;
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash[fd] = read_to_next_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	out = extract_line(stash[fd]);
	if (!out)
		return (NULL);
	stash[fd] = get_remaining_buffer(stash[fd]);
	return (out);
}
