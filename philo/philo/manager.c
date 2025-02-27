/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:56:00 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/27 15:10:18 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_manager *manager)
{
	int				i;

	i = 0;
	while (i < manager->count)
	{
		manager->philos[i].start_mutex = &(manager->start_mutex);
		manager->philos[i].print_mutex = &(manager->print_mutex);
		manager->philos[i].end_mutex = &(manager->end_mutex);
		manager->philos[i].id = i + 1;
		manager->philos[i].manager = manager;
		manager->philos[i].start_eating = i % 2;
		manager->philos[i].eat_reached = 0;
		pthread_mutex_init(&(manager->philos[i].update_meal), NULL);
		pthread_mutex_init(&(manager->philos[i].l_fork), NULL);
		i++;
	}
}

static int	create_threads(t_manager *manager)
{
	int				i;

	i = 0;
	while (i < manager->count)
	{
		if (pthread_create(&(manager->philos[i].thread), NULL,
				phi_start_routine, &(manager->philos[i])) == -1)
			return (0);
		i++;
	}
	if (pthread_create(&(manager->manager_thread), NULL,
			mngr_start_routine, manager) == -1)
		return (0);
	return (1);
}

static int	join_threads(t_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->count)
	{
		if (pthread_join(manager->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(manager->manager_thread, NULL) != 0)
		return (0);
	return (1);
}

int	init_threads(t_manager *manager)
{
	pthread_mutex_lock(&manager->start_mutex);
	init_philos(manager);
	if (!create_threads(manager))
		return (0);
	pthread_mutex_unlock(&manager->start_mutex);
	if (!join_threads(manager))
		return (0);
	exit_mngr(manager);
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
