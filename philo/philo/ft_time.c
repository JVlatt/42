/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:56:20 by mmanuell          #+#    #+#             */
/*   Updated: 2025/03/03 15:29:41 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("gettimeofday Error\n");
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	get_elapsed_time(long start_time)
{
	return (get_current_time() - start_time);
}

int	ft_usleep(long start_time, long duration,
t_manager *manager)
{
	long	start;

	start = get_elapsed_time(start_time);
	while ((get_elapsed_time(start_time) - start) < duration)
	{
		pthread_mutex_lock(&manager->end_mutex);
		if (manager->sim_end)
		{
			pthread_mutex_unlock(&manager->end_mutex);
			return (0);
		}
		pthread_mutex_unlock(&manager->end_mutex);
		usleep(100);
	}
	return (1);
}
