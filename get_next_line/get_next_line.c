/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:38:36 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/12 18:49:49 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer [BUFFER_SIZE];
	char		*out;
	static char	*savedbuffer;
	size_t		len;
	int			i;
	
	if(!savedbuffer)
	{
		savedbuffer = malloc (1);
		savedbuffer[0] = 0;
	}
	else if (savedbuffer[0] && ((i = ft_strchr_index(savedbuffer, '\n')) >= 0))
	{
		out = ft_strndup(savedbuffer, i + 1);
		savedbuffer = ft_strndup(savedbuffer + i + 1, ft_strlen(savedbuffer) - i);
		return (out);
	}
	i = 0;
	len = read(fd, buffer, sizeof(buffer));
	if (len <= 0)
		return (NULL);
	if ((i = ft_strchr_index(buffer, '\n')) >= 0)
	{
		if (savedbuffer[0])
			out = ft_strjoin(savedbuffer, ft_strndup(buffer, i));
		else
			out = ft_strndup(buffer, i + 1);
		if (!out)
			return (NULL);
		if (buffer[i + 1] != 0)
			savedbuffer = ft_strndup(buffer + i + 1, BUFFER_SIZE - i);
		else
			free(savedbuffer);
		return (out);
	}
	savedbuffer = ft_strjoin(savedbuffer, ft_strndup(buffer, BUFFER_SIZE));
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
