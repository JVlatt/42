/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mngr_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:59:48 by matt              #+#    #+#             */
/*   Updated: 2025/02/24 14:00:49 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_meals_reached(t_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->count)
	{
		if (!manager->philos[i].eat_reached)
			return (0);
		i++;
	}
	return (1);
}

static void	mngr_main_routine(t_manager *manager)
{
	int	i;

	while (!manager->sim_end)
	{
		i = 0;
		if (manager->philos[0].eat_goal > 0)
			manager->sim_end = check_meals_reached(manager);
		while (i < manager->count)
		{
			if (get_elapsed_time(manager->philos[i].last_meal)
				> manager->philos[i].die_time)
			{
				printf("%u Philosopher %d is dead\n",
					get_elapsed_time(manager->philos[i].start_time),
					manager->philos[i].id);
				manager->sim_end = 1;
				break ;
			}
			i++;
		}
	}
}

void	*mngr_start_routine(void *managerp)
{
	t_manager	*manager;

	manager = (t_manager *) managerp;
	pthread_mutex_lock(&manager->start_mutex);
	pthread_mutex_unlock(&manager->start_mutex);
	mngr_main_routine(manager);
	return (NULL);
}
