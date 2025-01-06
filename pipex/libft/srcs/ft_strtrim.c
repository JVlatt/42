/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:39:41 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/12 17:51:04 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_ischarset(char const *charset, char c)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	ft_gettrimstart(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (ft_ischarset(set, *(str + i)))
		i++;
	return (i);
}

static int	ft_gettrimend(char const *str, char const *set, int trimstart)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (ft_ischarset(set, str[i]) && i > trimstart)
		i--;
	return (i);
}

static void	ft_getstr(char *dest, char const *str, int trimstart, int trimend)
{
	int	i;

	i = 0;
	while (trimstart <= trimend)
	{
		dest[i] = str[trimstart];
		i++;
		trimstart++;
	}
	dest[i] = 0;
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		trimstart;
	int		trimend;
	size_t	totalsize;
	char	*trimstr;

	if (!*str)
	{
		trimstr = malloc(sizeof (char) * 1);
		if (!trimstr)
			return (NULL);
		trimstr[0] = 0;
		return (trimstr);
	}
	if (!*set)
		return (ft_strdup(str));
	trimstart = ft_gettrimstart(str, set);
	trimend = ft_gettrimend(str, set, trimstart);
	totalsize = trimend - trimstart + 1;
	if (totalsize == ft_strlen(str))
		return (ft_strdup(str));
	trimstr = malloc(sizeof (char) * (totalsize + 1));
	if (!trimstr)
		return (NULL);
	ft_getstr(trimstr, str, trimstart, trimend);
	return (trimstr);
}
