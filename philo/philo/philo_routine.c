/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/24 15:48:10 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	phi_main_routine(t_philosopher *philo)
{
	if (!philo->start_eating)
	{
		pthread_mutex_lock(&(philo->l_fork));
		printf("%u Philosopher %d has taken a fork\n",
			get_elapsed_time(philo->start_time),
			philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%u Philosopher %d has taken a fork\n",
			get_elapsed_time(philo->start_time),
			philo->id);
		philo->start_eating = 1;
	}
	eat_time(philo);
	pthread_mutex_unlock(&(philo->l_fork));
	pthread_mutex_unlock(philo->r_fork);
	bed_time(philo);
	printf("%u Philosopher %d is thinking\n",
		get_elapsed_time(philo->start_time),
		philo->id);
	if (!philo->manager->sim_end)
		phi_main_routine(philo);
}

void	*phi_start_routine(void *philop)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philop;
	pthread_mutex_lock(philo->start_mutex);
	philo->start_time = get_current_time();
	philo->last_meal = get_current_time();
	philo->eat_reached = 0;
	if (philo->start_eating)
	{
		pthread_mutex_lock(&(philo->l_fork));
		printf("%u Philosopher %d has taken a fork\n",
			get_elapsed_time(philo->start_time),
			philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%u Philosopher %d has taken a fork\n",
			get_elapsed_time(philo->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->start_mutex);
	phi_main_routine(philo);
	return (NULL);
}
