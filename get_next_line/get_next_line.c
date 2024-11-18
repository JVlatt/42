/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:38:36 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/18 12:58:42 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_to_next_line(int fd, char *stash)
{
	char		*buffer;
	size_t		len;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	len = 1;
	while (len > 0 && (ft_strchr_index(stash, '\n') < 0))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[len] = 0;
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*stash;
	int			i;

	if (!fd || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash = read_to_next_line(fd, stash);
	if (!stash)
		return (NULL);
	i = ft_strchr_index(stash, '\n') + 1;
	if (i <= 0)
	{
		free(stash);
		return (NULL);
	}
	out = ft_strtrim(stash, 0, i);
	stash = ft_strtrim(stash, i, ft_strlen(stash));
	return (out);
}

#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char *line;

	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
			i = atoi(argv[2]);
			while (i--)
			{
				line = get_next_line(fd);
				if (line)
					printf("%s", line);
				free(line);
			}
		close(fd);
		return (0);
	}
}
