/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:55 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/19 16:59:27 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	bed_time(t_philosopher *philo)
{
	printf("%u Philosopher %d is sleeping\n",
		get_elapsed_time(philo->start_time),
		philo->id);
	ft_usleep(philo->start_time, philo->sleep_time);
}

void	eat_time(t_philosopher *philo)
{
	printf("%u Philosopher %d is eating\n",
		get_elapsed_time(philo->start_time),
		philo->id);
	ft_usleep(philo->start_time, philo->eat_time);
	philo->last_meal = get_current_time();
	philo->eat_count += 1;
}
