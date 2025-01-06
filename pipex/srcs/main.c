/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:41:27 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/24 14:49:39 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	t_pipe	*pipe;
	if (argc == 5)
	{
		//Compute commands
		argv++;
		pipe = parse_args(argc, argv);
		return (0);
	}
	return (1);
}