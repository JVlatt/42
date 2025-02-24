/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:49:03 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/24 14:03:08 by matt             ###   ########.fr       */
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

typedef struct	s_manager	t_manager;

typedef struct s_philosopher
{
	unsigned int	start_time;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	last_meal;
	int				eat_count;
	int				eat_goal;
	unsigned int	eat_reached;
	unsigned int	state;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	pthread_t		thread;
	pthread_mutex_t	*start_mutex;
	unsigned int	start_eating;
	unsigned int	id;
	t_manager		*manager;
}	t_philosopher;

typedef struct s_manager
{
	t_philosopher	*philos;
	int				count;
	pthread_mutex_t	start_mutex;
	int				sim_end;
	pthread_t		manager_thread;
}	t_manager;

void			*philo_routine(void *arg);

// PARSING

int				check_args(int argc, char **argv);
void			init_manager(t_manager *manager, int argc, char **argv);

//	MANAGER

int				init_threads(t_manager *manager);

//	ROUTINE

void			*phi_start_routine(void *philop);
void			*mngr_start_routine(void *managerp);
void			eat_time(t_philosopher *philo);
void			bed_time(t_philosopher *philo);

//	TIME

unsigned int	get_current_time(void);
unsigned int	get_elapsed_time(unsigned int start_time);
int				ft_usleep(unsigned int start_time, unsigned int duration);

// UTILS

int				ft_isnum(char *str);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);

//	DEBUG

void			print_philos_data(t_manager *manager);

#endif
