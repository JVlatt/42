/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:28:24 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/13 21:40:53 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	try_exec_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;
	int		ispath;

	ispath = 0;
	cmd_args = ft_split(cmd, ' ');
	if (ft_strchr(cmd_args[0], '/'))
	{
		cmd_path = cmd_args[0];
		ispath = 1;
	}
	else
		cmd_path = get_path(envp, cmd_args[0]);
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		ft_putstr_fd("Command error : ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" not found !\n", 2);
		ft_free_tab(cmd_args);
		if (!ispath)
			free(cmd_path);
		exit(0);
	}
}

static int	exec_child(int *pipe_fd, int index, char **argv, int argc)
{
	if (index - 2 == 0)
	{
		close(pipe_fd[0]);
		pipe_fd[0] = ft_open(argv[1], 0);
		if (pipe_fd[0] == -1)
		{
			perror("File opening issue");
			dup2(pipe_fd[1], 1);
			close(pipe_fd[1]);
			return (0);
		}
		dup2(pipe_fd[0], 0);
	}
	if (index == argc - 2)
	{
		close(pipe_fd[1]);
		pipe_fd[1] = ft_open(argv[argc - 1], 1);
		if (pipe_fd[1] == -1)
		{
			perror("File opening issue");
			close(pipe_fd[0]);
			return (0);
		}
	}
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	return (1);
}

static pid_t	exec_pipe(int argc, char **argv, char **envp, int index)
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
		if (exec_child(pipe_fd, index, argv, argc))
			try_exec_cmd(argv[index], envp);
		else
			exit(0);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	pid_t	pids[argc - 3];
	int		*exit_code;

	if (argc < 5)
	{
		ft_putstr_fd("infile cmd1 ... cmdn outfile", 2);
		return (1);
	}
	i = 2;
	while (i < argc - 1)
	{
		pids[i - 2] = exec_pipe(argc, argv, envp, i);
		i++;
	}
	i = 0;
	while (i < argc - 3)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
	return (0);
}
