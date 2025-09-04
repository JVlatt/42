/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:35:30 by mmanuell          #+#    #+#             */
/*   Updated: 2025/03/03 16:44:57 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	while (--argc)
	{
		if (!ft_isnum(argv[argc]))
			return (0);
		if (ft_strlen(argv[argc]) > 11)
			return (0);
		if (ft_atol(argv[argc]) > INT_MAX || ft_atol(argv[argc]) < INT_MIN)
			return (0);
	}
	return (1);
}

static t_philosopher	*parse_data(int argc, char **argv)
{
	t_philosopher	*philos;
	int				count;

	count = ft_atoi(argv[1]);
	philos = ft_calloc(count, sizeof(t_philosopher));
	if (!philos)
		return (NULL);
	while (count--)
	{
		philos[count].die_time = ft_atoi(argv[2]);
		philos[count].eat_time = ft_atoi(argv[3]);
		philos[count].sleep_time = ft_atoi(argv[4]);
		philos[count].eat_count = 0;
		if (argc == 6)
			philos[count].eat_goal = ft_atoi(argv[5]);
		else
			philos[count].eat_goal = -1;
	}
	while (count++ < ft_atoi(argv[1]) - 2)
		philos[count].r_fork = &(philos[count + 1].l_fork);
	philos[count].r_fork = &(philos[0].l_fork);
	return (philos);
}

int	init_manager(t_manager *manager, int argc, char **argv)
{
	manager->count = ft_atoi(argv[1]);
	manager->philos = parse_data(argc, argv);
	if (!manager->philos)
		return (0);
	manager->sim_end = 0;
	if (pthread_mutex_init(&manager->start_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&manager->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&manager->end_mutex, NULL) != 0)
		return (0);
	return (1);
}
