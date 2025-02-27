/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/27 18:44:19 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	phi_main_routine(t_philosopher *philo)
{
	if (philo->start_eating)
	{
		take_fork(philo, philo->r_fork);
		take_fork(philo, &(philo->l_fork));
	}
	else
	{
		take_fork(philo, &(philo->l_fork));
		take_fork(philo, philo->r_fork);
	}
	eat_time(philo);
	if (philo->start_eating)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&(philo->l_fork));
	}
	else
	{
		pthread_mutex_unlock(&(philo->l_fork));
		pthread_mutex_unlock(philo->r_fork);
	}
	if (bed_time(philo))
		return (phi_main_routine(philo));
	return (1);
}

void	*phi_start_routine(void *philop)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philop;
	philo->start_time = get_current_time();
	philo->last_meal = philo->start_time;
	if (!philo->start_eating)
		ft_usleep(philo->start_time, philo->eat_time / 2, philo->manager);
	phi_main_routine(philo);
	return (NULL);
}
