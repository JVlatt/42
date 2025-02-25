/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/25 18:00:33 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	phi_start_eat_main_routine(t_philosopher *philo)
// {
// 	eat_time(philo);
// 	pthread_mutex_unlock(&(philo->l_fork));
// 	pthread_mutex_unlock(philo->r_fork);
// 	bed_time(philo);
// 	take_fork(philo, &(philo->l_fork));
// 	take_fork(philo, philo->r_fork);
// 	if (!philo->manager->sim_end)
// 		phi_start_eat_main_routine(philo);
// }

static void	phi_main_routine(t_philosopher *philo)
{
	take_fork(philo, &(philo->l_fork));
	take_fork(philo, philo->r_fork);
	eat_time(philo);
	pthread_mutex_unlock(&(philo->l_fork));
	pthread_mutex_unlock(philo->r_fork);
	bed_time(philo);
	if (!check_simend(philo->manager))
		phi_main_routine(philo);
}

void	*phi_start_routine(void *philop)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philop;
	philo->start_time = get_current_time();
	philo->last_meal = philo->start_time;
	// pthread_mutex_init(&philo->update_meal, NULL);
	// pthread_mutex_lock(philo->start_mutex);
	// pthread_mutex_unlock(philo->start_mutex);
	// if (philo->start_eating)
	// {
	// 	take_fork(philo, &(philo->l_fork));
	// 	take_fork(philo, philo->r_fork);
	// }
	// if (philo->start_eating)
	// 	phi_start_eat_main_routine(philo);
	// else
	// {
	// 	ft_usleep(philo->start_time, philo->eat_time / 2, philo->manager);
	// 	phi_main_routine(philo);
	// }
	if (!philo->start_eating)
		ft_usleep(philo->start_time, philo->eat_time / 2, philo->manager);
	phi_main_routine(philo);
	return (NULL);
}
