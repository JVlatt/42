/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:42 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/18 20:04:56 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *philop)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) philop;
	pthread_mutex_lock(philo->start_mutex);
	philo->start_time = get_current_time();
	printf("My Start Time is %u \n", get_elapsed_time(philo->start_time));
	usleep(10000);
	printf("After Sleep      %u \n", get_elapsed_time(philo->start_time));
	pthread_mutex_unlock(philo->start_mutex);
	return (NULL);
}
