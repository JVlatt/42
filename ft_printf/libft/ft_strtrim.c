/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:39:41 by mmanuell          #+#    #+#             */
/*   Updated: 2024/10/29 19:34:14 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_gettrimstart(char const *s1, char const *set)
{
	int	i;
	int	setlen;

	i = 0;
	setlen = ft_strlen(set);
	while (i < setlen)
	{
		if (*(s1 + i) != *(set + i))
			return (0);
		i++;
	}
	return (i);
}

static int	ft_gettrimend(char const *s1, char const *set, int trimstart)
{
	int	i;
	int	j;

	i = ft_strlen(set) - 1;
	j = ft_strlen(s1) - 1;
	if ((i == j && trimstart > 0) || *(s1 + j) != *(set + i))
		return (ft_strlen(s1) - 1);
	while (i >= 0)
	{
		if (*(s1 + j) != *(set + i))
			return (ft_strlen(s1) - 1);
		j--;
		i--;
	}
	return (j);
}

static void	ft_getstr(char *dest, char const *s1, int trimstart, int trimend)
{
	int	i;

	i = 0;
	while (trimstart <= trimend)
	{
		dest[i] = s1[trimstart];
		i++;
		trimstart++;
	}
	dest[i] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		trimstart;
	int		trimend;
	size_t	totalsize;
	char	*trimstr;

	if (!*s1)
	{
		trimstr = malloc(sizeof (char) * 1);
		if (!trimstr)
			return (NULL);
		trimstr[0] = 0;
		return (trimstr);
	}
	if (!*set || ft_strlen(set) > ft_strlen(s1))
		return (ft_strdup(s1));
	trimstart = ft_gettrimstart(s1, set);
	trimend = ft_gettrimend(s1, set, trimstart);
	totalsize = trimend - trimstart + 1;
	if (totalsize == ft_strlen(s1))
		return (ft_strdup(s1));
	trimstr = malloc(sizeof (char) * (totalsize + 1));
	if (!trimstr)
		return (NULL);
	ft_getstr(trimstr, s1, trimstart, trimend);
	return (trimstr);
}
