/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:43:24 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/14 17:15:48 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"



int	main(int argc, char **argv, char **envp)
{
	
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
		{
			ft_putstr_fd("here_doc LIMITER cmd cmd1 file", 2);
			return (1);
		}
		parse_here_doc(argc, argv, envp);
	}
	else
	{
		if (argc < 5)
		{
			ft_putstr_fd("infile cmd1 ... cmdn outfile", 2);
			return (1);
		}
		parse_pipe(argc, argv, envp);
	}
	return (1);
}
