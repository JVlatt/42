/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:56:20 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/19 13:41:57 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

unsigned int	get_elapsed_time(unsigned int start_time)
{
	return (get_current_time() - start_time);
}

int	ft_usleep(unsigned int start_time, unsigned int duration)
{
	unsigned int	start;

	start = get_elapsed_time(start_time);
	while ((get_elapsed_time(start_time) - start) < duration)
		usleep(500);
	return (0);
}
