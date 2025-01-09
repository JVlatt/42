/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:28:24 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/09 20:55:27 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	try_exec_cmd(char *cmd, char **envp)
{
	char **cmd_args;
	char *cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_path(envp, cmd_args[0]);
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		ft_putstr_fd("Command error : ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" not found !\n", 2);
		ft_free_tab(cmd_args);
		free(cmd_path);
		exit(0);
	}
	else
	{
		ft_free_tab(cmd_args);
		free(cmd_path);
		exit(1);
	}
}
static void	exec_child(int *pipe_fd, int index, char **argv, int argc)
{
	if (index - 2 == 0)
	{
		close(pipe_fd[0]);
		pipe_fd[0] = ft_open(argv[1], 0);
		dup2(pipe_fd[0], 0);
	}
	if (index == argc - 2)
	{
		close(pipe_fd[1]);
		pipe_fd[1] = ft_open(argv[argc - 1], 1);
	}
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
}

static void	exec_pipe(int argc, char **argv, char **envp, int index)
{
	pid_t	pid;
	int		pipe_fd[2];
	
	if (pipe(pipe_fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		exec_child(pipe_fd, index, argv, argc);
		try_exec_cmd(argv[index], envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	
	if (argc < 5)
	{
		ft_putstr_fd("infile cmd1 ... cmdn outfile", 2);
		return (1);
	}
	// input_fd = ft_open(argv[1], 0);
	// output_fd = ft_open(argv[argc - 1], 1);
	// dup2(input_fd, 0);
	// close(input_fd);
	i = 2;
	while (i < argc - 1)
	{
		exec_pipe(argc, argv, envp, i);
		i++;
	}
	// dup2(output_fd, 1);
	// close(output_fd);
	// try_exec_cmd(argv[argc - 2], envp);
}