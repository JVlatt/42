/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:35:30 by mmanuell          #+#    #+#             */
/*   Updated: 2025/02/06 16:50:27 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philosopher	*parse_data(int argc, char **argv)
{
	t_philosopher	*philos;

	return (philos);
}

t_manager	*init_manager(int argc, char **argv)
{
	t_manager	*manager;

	manager = ft_calloc(1, sizeof(t_manager));
	manager->philos = parse_data(argc, argv);
	return (manager);
}