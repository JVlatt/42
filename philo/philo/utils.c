/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:21:20 by mmanuell          #+#    #+#             */
/*   Updated: 2025/03/03 16:46:09 by mmanuell         ###   ########.fr       */
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

void	exit_mngr(t_manager *manager)
{
	int	i;

	pthread_mutex_destroy(&manager->start_mutex);
	pthread_mutex_destroy(&manager->print_mutex);
	pthread_mutex_destroy(&manager->end_mutex);
	i = 0;
	while (i < manager->count)
	{
		pthread_mutex_destroy(&manager->philos[i].l_fork);
		pthread_mutex_destroy(&manager->philos[i].update_meal);
		i++;
	}
	free(manager->philos);
}

void	print_philos_data(t_manager *manager)
{
	int	i;

	i = 0;
	printf ("==** %d Philosophers **==\n\n", manager->count);
	while (i < manager->count)
	{
		printf ("===== %d =====\n", i);
		printf ("Thread ID : %lu\n", manager->philos[i].thread);
		printf ("Time To Die : %ld\n", manager->philos[i].die_time);
		printf ("Time To Eat : %ld\n", manager->philos[i].eat_time);
		printf ("Time To Sleep : %ld\n", manager->philos[i].sleep_time);
		printf ("Number To Eat : %d\n", manager->philos[i].eat_goal);
		printf ("Left Fork   : %p\n", &(manager->philos[i].l_fork));
		printf ("Right Fork *: %p\n", manager->philos[i].r_fork);
		printf ("Start Eating: %d\n", manager->philos[i].start_eating);
		printf ("==========================\n\n");
		i++;
	}
}

void	print_philo_data(t_philosopher *philo)
{
	printf("===== %d =====\n", philo->id);
	printf("Thread ID : %lu\n", philo->thread);
	printf("Time To Die : %ld\n", philo->die_time);
	printf("Time To Eat : %ld\n", philo->eat_time);
	printf("Time To Sleep : %ld\n", philo->sleep_time);
	printf("Number To Eat : %d\n", philo->eat_goal);
	printf("Left Fork   : %p\n", &(philo->l_fork));
	printf("Right Fork *: %p\n", philo->r_fork);
	printf("Start Eating: %d\n", philo->start_eating);
	printf("==========================\n\n");
}
