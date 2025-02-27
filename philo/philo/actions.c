/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:55 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/27 13:32:40 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philosopher *philo, const char *action)
{
	pthread_mutex_lock(philo->print_mutex);
	if (!check_simend(philo->manager))
		printf("%ld %d %s\n",
			get_elapsed_time(philo->start_time),
			philo->id,
			action);
	pthread_mutex_unlock(philo->print_mutex);
}

int	check_simend(t_manager *manager)
{
	int	ret;

	pthread_mutex_lock(&manager->end_mutex);
	ret = manager->sim_end;
	pthread_mutex_unlock(&manager->end_mutex);
	return (ret);
}

int	bed_time(t_philosopher *philo)
{
	if (check_simend(philo->manager))
		return (0);
	print_action(philo, "is sleeping");
	if (!ft_usleep(philo->start_time, philo->sleep_time, philo->manager))
		return (0);
	print_action(philo, "is thinking");
	return (1);
}

int	eat_time(t_philosopher *philo)
{
	if (check_simend(philo->manager))
		return (0);
	pthread_mutex_lock(&philo->update_meal);
	print_action(philo, "is eating");
	philo->last_meal = get_current_time();
	philo->eat_count += 1;
	if (philo->eat_count >= philo->eat_goal)
		philo->eat_reached = 1;
	pthread_mutex_unlock(&philo->update_meal);
	return (ft_usleep(philo->start_time, philo->eat_time, philo->manager));
}

int	take_fork(t_philosopher *philo, pthread_mutex_t *fork)
{
	if (check_simend(philo->manager))
		return (0);
	pthread_mutex_lock(fork);
	if (check_simend(philo->manager))
	{
		pthread_mutex_unlock(fork);
		return (0);
	}
	print_action(philo, "has taken a fork");
	return (1);
}
