/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:38:36 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/20 18:26:39 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
static char	*extract_line(char *stash)
{
	int		i;
	char	*out;
	int		len;
	
	len = 0;
	i = 0;
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
	out[j] = 0;
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
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash = read_to_next_line(fd, stash);
	if (!stash)
		return (NULL);
	out = extract_line(stash);
	stash = get_remaining_buffer(stash);
	return (out);
}

/*#include <stdio.h>
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
}*/
/*
#include <stdio.h>
#include <fcntl.h>
int    main(void)
{
    char *line;
    char *name = "read_error.txt";
    int fd = open(name, O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    line = get_next_line(10);
    printf("%s\n", line);
    free(line);
    close(fd);
    fd = open(name, O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    return (0);
}*/
