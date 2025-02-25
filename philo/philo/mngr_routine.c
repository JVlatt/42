/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mngr_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:59:48 by matt              #+#    #+#             */
/*   Updated: 2025/02/25 18:40:31 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
				printf("%ld %d died\n",
					get_elapsed_time(manager->philos[i].start_time),
					manager->philos[i].id);
				// printf("start time : %ld \n", manager->philos[i].start_time);
				// printf("current time : %ld \n", get_current_time());
				// printf("die time : %ld \n", manager->philos[i].die_time);
				// printf("last meal: %ld \n", get_elapsed_time(manager->philos[i].last_meal));
				pthread_mutex_lock(&manager->end_mutex);
				manager->sim_end = 1;
				pthread_mutex_unlock(&manager->end_mutex);
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
	ft_usleep(get_current_time(), 10, manager);
	mngr_main_routine(manager);
	return (NULL);
}
