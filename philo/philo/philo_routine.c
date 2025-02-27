/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/27 11:32:38 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	phi_main_routine(t_philosopher *philo)
{
	if (philo->id % 2)
	{
		if (!take_fork(philo, &(philo->l_fork)))
			return (exit_philo(philo));
		if (!take_fork(philo, philo->r_fork))
			return (exit_philo(philo));
	}
	else
	{
		if (!take_fork(philo, philo->r_fork))
			return (exit_philo(philo));
		if (!take_fork(philo, &(philo->l_fork)))
			return (exit_philo(philo));
	}
	if (!eat_time(philo))
		return (exit_philo(philo));
	pthread_mutex_unlock(&(philo->l_fork));
	pthread_mutex_unlock(philo->r_fork);
	if (!bed_time(philo))
		return (exit_philo(philo));
	return (phi_main_routine(philo));
}

void	*phi_start_routine(void *philop)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philop;
	pthread_mutex_init(&(philo->l_fork), NULL);
	philo->start_time = get_current_time();
	philo->last_meal = philo->start_time;
	if (!philo->start_eating)
		ft_usleep(philo->start_time, philo->eat_time / 2, philo->manager);
	phi_main_routine(philo);
	return (NULL);
}
