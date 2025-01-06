/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:13:59 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/27 14:30:47 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_strjoinbuffer(char *stash, char *buffer)
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
