/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:49:03 by mmanuell          #+#    #+#             */
/*   Updated: 2025/03/03 16:46:25 by mmanuell         ###   ########.fr       */
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

typedef struct s_manager	t_manager;

typedef struct s_philosopher
{
	long			start_time;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			last_meal;
	int				eat_count;
	int				eat_goal;
	unsigned int	eat_reached;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	update_meal;
	pthread_t		thread;
	pthread_mutex_t	*start_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*end_mutex;
	unsigned int	start_eating;
	unsigned int	id;
	t_manager		*manager;
}	t_philosopher;

typedef struct s_manager
{
	t_philosopher	*philos;
	int				count;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;
	int				sim_end;
	pthread_t		manager_thread;
}	t_manager;

void			*philo_routine(void *arg);

// PARSING

int				check_args(int argc, char **argv);
int				init_manager(t_manager *manager, int argc, char **argv);

//	MANAGER

int				init_threads(t_manager *manager);

//	ROUTINE

void			*phi_start_routine(void *philop);
void			*phi_solo_routine(void *philop);
void			*mngr_start_routine(void *managerp);
int				eat_time(t_philosopher *philo);
int				bed_time(t_philosopher *philo);
int				take_fork(t_philosopher *philo, pthread_mutex_t *fork);
int				check_simend(t_manager *manager);
void			print_action(t_philosopher *philo, const char *action);

//	TIME

long			get_current_time(void);
long			get_elapsed_time(long start_time);
int				ft_usleep(long start_time, long duration,
					t_manager *manager);

// UTILS

int				ft_isnum(char *str);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
void			exit_mngr(t_manager *manager);

//	DEBUG

void			print_philos_data(t_manager *manager);
void			print_philo_data(t_philosopher *philo);
#endif
