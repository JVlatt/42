/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/19 17:07:59 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *philop)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) philop;
	pthread_mutex_lock(philo->start_mutex);
	philo->start_time = get_current_time();
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->start_mutex);
	main_routine(philo);
	return (NULL);
}

void	main_routine(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->l_fork));
	pthread_mutex_lock(philo->r_fork);
	eat_time(philo);
	pthread_mutex_unlock(&(philo->l_fork));
	pthread_mutex_unlock(philo->r_fork);
	bed_time(philo);
	printf("%u Philosopher %d is thinking\n",
		get_elapsed_time(philo->start_time),
		philo->id);
	//main_routine(philo);
}
