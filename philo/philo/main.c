/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:54:11 by mmanuell          #+#    #+#             */
/*   Updated: 2025/03/03 17:47:28 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_manager	manager;

	if (check_args(argc, argv))
	{
		if (!init_manager(&manager, argc, argv))
		{
			printf("Error : Manager Initialization\n");
			return (1);
		}
		if (!init_threads(&manager))
		{
			printf("Error : Thread Initialization\n");
			return (1);
		}
		return (0);
	}
	else
		printf("Invalid Arguments\n");
	return (1);
}
