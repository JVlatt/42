/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:41:27 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/07 14:01:50 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipe;

	// char *args[3];
	
	// args[0] = "ls";
	// args[1] = "-l";
	// args[2] = NULL;
	// execve("/bin/ls", args, NULL);
	
	if (argc >= 5)
	{
		//Compute commands
		argv++;
		pipe = parse_args(argc - 1, argv, envp);
		execute_pipe(pipe);
		ft_free_pipe(pipe, 2);
		return (0);
	}
	return (1);
}