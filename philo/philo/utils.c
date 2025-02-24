/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:21:20 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/24 15:44:17 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	print_philos_data(t_manager *manager)
{
	int	i;

	i = 0;
	printf ("==** %d Philosophers **==\n\n", manager->count);
	while (i < manager->count)
	{
		printf ("===== Philosopher %d =====\n", i);
		printf ("Thread ID : %lu\n", manager->philos[i].thread);
		printf ("Time To Die : %d\n", manager->philos[i].die_time);
		printf ("Time To Eat : %d\n", manager->philos[i].eat_time);
		printf ("Time To Sleep : %d\n", manager->philos[i].sleep_time);
		printf ("Number To Eat : %d\n", manager->philos[i].eat_goal);
		printf ("Left Fork   : %p\n", &(manager->philos[i].l_fork));
		printf ("Right Fork *: %p\n", manager->philos[i].r_fork);
		printf ("Start Eating: %u\n", manager->philos[i].start_eating);
		printf ("==========================\n\n");
		i++;
	}
}
