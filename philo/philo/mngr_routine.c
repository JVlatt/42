/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mngr_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:59:48 by matt              #+#    #+#             */
/*   Updated: 2025/02/27 18:44:57 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_philo(t_manager *manager, int i)
{
	pthread_mutex_lock(&manager->print_mutex);
	pthread_mutex_lock(&manager->end_mutex);
	printf("%ld %d %s\n",
		get_elapsed_time(manager->philos[i].start_time),
		manager->philos[i].id,
		"died");
	manager->sim_end = 1;
	pthread_mutex_unlock(&manager->end_mutex);
	pthread_mutex_unlock(&manager->print_mutex);
}

static int	check_meals_reached(t_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->count)
	{
		pthread_mutex_lock(&(manager->philos[i].update_meal));
		if (!manager->philos[i].eat_reached)
		{
			pthread_mutex_unlock(&(manager->philos[i].update_meal));
			return (0);
		}
		pthread_mutex_unlock(&(manager->philos[i].update_meal));
		i++;
	}
	return (1);
}

static void	mngr_main_routine(t_manager *manager)
{
	int	i;
	int	check_meals;

	while (!manager->sim_end)
	{
		i = 0;
		if (manager->philos[0].eat_goal > 0)
		{
			check_meals = check_meals_reached(manager);
			pthread_mutex_lock(&manager->end_mutex);
			manager->sim_end = check_meals;
			pthread_mutex_unlock(&manager->end_mutex);
		}
		while (i < manager->count && !manager->sim_end)
		{
			pthread_mutex_lock(&(manager->philos[i].update_meal));
			if (get_elapsed_time(manager->philos[i].last_meal)
				>= manager->philos[i].die_time)
			{
				kill_philo(manager, i);
			}
			pthread_mutex_unlock(&(manager->philos[i].update_meal));
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
	ft_usleep(get_current_time(), 50, manager);
	mngr_main_routine(manager);
	return (NULL);
}
