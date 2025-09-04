/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:45:28 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 19:26:28 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count ++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static int	ft_lenword(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*ft_cpyword(char const *str, char c)
{
	char	*dup;
	int		i;
	int		size;

	i = 0;
	size = ft_lenword(str, c);
	dup = malloc(size + 1);
	if (!dup)
		return (NULL);
	while (str[i] && i < size)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

static char	**ft_freeexit(char **array, int index)
{
	while (index-- >= 0)
		free(array[index]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**out;
	int		i;
	int		k;

	i = 0;
	k = 0;
	out = malloc(sizeof (char *) * (ft_count_words(str, c) + 1));
	if (!out)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			out[k] = ft_cpyword(str + i, c);
			if (!out)
				return (ft_freeexit(out, k));
			k++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	out[k] = NULL;
	return (out);
}
