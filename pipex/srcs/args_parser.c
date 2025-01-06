/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:15:22 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/24 14:59:49 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipe	*init_pipe(int argc)
{
	t_pipe	*pipe;
	
	pipe = malloc(sizeof(t_pipe));
	if (!pipe)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	pipe->cmd_args = malloc(sizeof(char *) * argc - 2);
	if (!pipe->cmd_args)
	{
		ft_free_pipe(pipe, 0);
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	pipe->cmd_paths = malloc(sizeof(char *) * argc - 2);
	if (!pipe->cmd_paths)
	{
		ft_free_pipe(pipe, 1);
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
}

void	get_files(t_pipe *pipe, char *file1, char *file2)
{
	int	infd;
	int	outfd;

	infd = open(file1, O_RDONLY, 0777);
	if (infd == -1)
	{
		perror("infile error");
		exit(EXIT_FAILURE);
	}
	outfd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd == -1)
	{
		perror("outfile error");
		exit(EXIT_FAILURE);
	}
	pipe->infile = infd;
	pipe->outfile = outfd;
}

t_pipe	*get_commands(t_pipe *pipe, char *command1, char *command2)
{
	char	**split_cmd1;
	char	**split_cmd2;

	split_cmd1 = ft_split(command1, ' ');
	if (!split_cmd1)
	{
		ft_free_pipe(pipe, 2);
		perror("split cmd 1 error");
		exit(EXIT_FAILURE);
	}
	split_cmd2 = ft_split(command2, ' ');
	if (!split_cmd2)
	{
		ft_free_pipe(pipe, 2);
		perror("split cmd 1 error");
		exit(EXIT_FAILURE);
	}
	pipe->cmd_paths;
}

t_pipe	*parse_args(int argc, char **args)
{
	t_pipe	*pipe;

	pipe = init_pipe(argc);
	get_files(pipe, args[0], args[3]);
	get_commands(pipe, args[1], args[2]);
	
}