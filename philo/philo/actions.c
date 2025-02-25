/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:55 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/25 18:25:01 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_simend(t_manager *manager)
{
	int	ret;

	pthread_mutex_lock(&manager->end_mutex);
	ret = manager->sim_end;
	pthread_mutex_unlock(&manager->end_mutex);
	return (ret);
}

void	bed_time(t_philosopher *philo)
{
	if (check_simend(philo->manager))
		exit (0);
	printf("%ld %d is sleeping\n",
		get_elapsed_time(philo->start_time),
		philo->id);
	ft_usleep(philo->start_time, philo->sleep_time, philo->manager);
	printf("%ld %d is thinking\n",
		get_elapsed_time(philo->start_time),
		philo->id);
}

void	eat_time(t_philosopher *philo)
{
	if (check_simend(philo->manager))
		exit (0);
	pthread_mutex_lock(&philo->update_meal);
	printf("%ld %d is eating\n",
		get_elapsed_time(philo->start_time),
		philo->id);
	philo->last_meal = get_current_time();
	philo->eat_count += 1;
	if (philo->eat_count >= philo->eat_goal)
		philo->eat_reached = 1;
	pthread_mutex_unlock(&philo->update_meal);
	ft_usleep(philo->start_time, philo->eat_time, philo->manager);
}

void	take_fork(t_philosopher *philo, pthread_mutex_t *fork)
{
	if (check_simend(philo->manager))
		exit (0);
	pthread_mutex_lock(fork);
	if (check_simend(philo->manager))
		exit (0);
	printf("%ld %d has taken a fork\n",
		get_elapsed_time(philo->start_time),
		philo->id);
}
