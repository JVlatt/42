/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:49:03 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/18 20:01:17 by mmanuell         ###   ########.fr       */
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

struct	s_philosopher;

typedef struct s_philosopher
{
	unsigned int	start_time;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	eat_nb;
	unsigned int	state;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	pthread_t		thread;
	pthread_mutex_t	*start_mutex;
}	t_philosopher;

typedef struct s_manager
{
	t_philosopher	*philos;
	int				count;
	pthread_mutex_t	start_mutex;
}	t_manager;

void			*philo_routine(void *arg);

// PARSING

int				check_args(int argc, char **argv);
t_manager		*init_manager(int argc, char **argv);

//	MANAGER

int				init_threads(t_manager *manager);

//	ROUTINE

void			*start_routine(void *pmanager);
//	TIME

unsigned int	get_current_time(void);
unsigned int	get_elapsed_time(unsigned int start_time);

// UTILS

int				ft_isnum(char *str);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);

//	DEBUG

void			print_philos_data(t_manager *manager);

#endif