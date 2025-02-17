/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:46:01 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/06 16:54:01 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9')
			&& *str != '-' && *str != '+')
			return (0);
		if (*str == '-' || *str == '+')
		{
			str++;
			while (*str && *str >= '0' && *str <= '9')
				str++;
			if (*str)
				return (0);
		}
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (sign * result);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;
	size_t	i;

	if (nmemb * size > 2147483647)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)buffer)[i] = 0;
		i++;
	}
	return (buffer);
}
