/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <matt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:54:11 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/19 14:06:53 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_manager	manager;

	if (check_args(argc, argv))
	{
		init_manager(&manager, argc, argv);
		init_threads(&manager);
	}
	else
		printf("Invalid Arguments\n");
	return (1);
}

// fsanatize=threads

// usleep (unsigned int usecs)
// => 0 | -1 + errno

// int gettimeofday(struct timeval *tv, struct timezone *tz)
// => 0 | -1 + errno					should be NULL

// struct timeval
// {
// 	time_t tv_sec;		 /* seconds */
// 	suseconds_t tv_usec; /* microseconds */
// };

// struct timezone
// {
// 	int tz_minuteswest; /* minutes west of Greenwich */
// 	int tz_dsttime;		/* type of DST correction */
// };

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//						void *(*start_routine) (void *), void *arg)
// => 0 | -1 + errno *thread undefined
//
//	pthread_t *thread => thread IDs buffer

//  void *(*start_routine) (void *) => routine with *arg as argument
//
// int pthread_detach(pthread_t thread)
//
// => 0 | errno
//
// int pthread_join(pthread_t thread, void **retval) => waitpid equivalent
//										NULL
// => 0 | errno
//
// int pthread_mutex_init(pthread_mutex_t *restrict mutex,
//           	const pthread_mutexattr_t *restrict attr);
//										NULL
// => 0 | errno
//
// int pthread_mutex_destroy(pthread_mutex_t *mutex)
//									=> ne pas destroy un mutex lock !!
//
// => 0 | errno
// int pthread_mutex_lock(pthread_mutex_t *mutex);
// int pthread_mutex_trylock(pthread_mutex_t *mutex);
// int pthread_mutex_unlock(pthread_mutex_t *mutex);
