/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:49:03 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/06 17:48:21 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philosopher
{
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nb;
	int				state;
	t_philosopher	r_neighbor;
	t_philosopher	*l_neighbor;
}	t_philosopher;

typedef struct s_manager
{
	pthread_t		*t_ids;
	t_philosopher	*philos;
}	t_manager;

void	*philo_routine(void *arg);

// UTILS

int		ft_isnum(char *str);
int		ft_atoi(const char *str);

#endif