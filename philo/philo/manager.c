/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:56:00 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/18 19:46:37 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_manager *manager)
{
	int				i;
	pthread_mutex_t	mutex;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	manager->start_mutex = mutex;
	pthread_mutex_lock(&mutex);
	while (i < manager->count)
	{
		manager->philos[i].start_mutex = &mutex;
		if (pthread_create(&(manager->philos[i].thread), NULL,
				start_routine, &(manager->philos[i])) == -1)
			return (0);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	i = 0;
	while (i < manager->count)
	{
		if (pthread_join(manager->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	print_philos_data(manager);
	return (1);
}

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//						void *(*start_routine) (void *), void *arg)
// => 0 | -1 + errno *thread undefined
//
//	pthread_t *thread => thread IDs buffer

//  void *(*start_routine) (void *) => routine with *arg as argument
//
// int pthread_detach(pthread_t thread)
//
// => 0 | errno
//
// int pthread_join(pthread_t thread, void **retval) => waitpid equivalent
//										NULL
// => 0 | errno