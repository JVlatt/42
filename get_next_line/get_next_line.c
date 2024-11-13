/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:38:36 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/13 10:49:15 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer [BUFFER_SIZE + 1];
	char		*out;
	static char	*stash;
	size_t		len;
	int			i;
	
	if(!stash)
		stash = ft_calloc_bzero(1,1);
	else if (stash[0] && ((i = ft_strchr_index(stash, '\n')) >= 0))
	{
		out = ft_strndup(stash, i + 1);
		stash = ft_strndup(stash + i + 1, ft_strlen(stash) - i);
		return (out);
	}
	i = 0;
	len = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	if (len <= 0)
		return (NULL);
	if ((i = ft_strchr_index(buffer, '\n')) >= 0)
	{
		if (stash[0])
			out = ft_strjoin(stash, ft_strndup(buffer, i + 1));
		else
			out = ft_strndup(buffer, i + 1);
		if (!out)
			return (NULL);
		if (buffer[i] != 0)
			stash = ft_strndup(buffer + i + 1, BUFFER_SIZE + 1 - i);
		else
			free(stash);
		return (out);
	}
	stash = ft_strjoin(stash, ft_strndup(buffer, BUFFER_SIZE));
	return (get_next_line(fd));
}

#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			i = atoi(argv[2]);
			while (i--)
				printf("%s", get_next_line(fd));
		}
		close(fd);
		return (0);
	}
}
