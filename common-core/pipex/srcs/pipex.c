/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:28:24 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/14 20:02:17 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	try_exec_cmd(t_parse_infos *parse_infos, int index)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(parse_infos->argv[index], ' ');
	if (!cmd_args[0])
	{
		ft_putstr_fd("Invalid Argument\n", 2);
		ft_free_tab(cmd_args);
		ft_exit(EXIT_FAILURE, parse_infos);
	}
	if (ft_strchr(cmd_args[0], '/'))
		cmd_path = cmd_args[0];
	else
		cmd_path = get_path(parse_infos, cmd_args);
	if (execve(cmd_path, cmd_args, parse_infos->envp) == -1)
	{
		perror("Command not found");
		ft_free_tab(cmd_args);
		if (cmd_path != cmd_args[0])
			free(cmd_path);
		ft_exit(EXIT_FAILURE, parse_infos);
	}
}

static int	redirect_child(int *pipe_fd, int index,
						t_parse_infos *parse_infos, int start)
{
	if (index - start == 0)
	{
		close(pipe_fd[0]);
		pipe_fd[0] = ft_open(parse_infos->argv[1], 0);
		if (pipe_fd[0] == -1)
		{
			dup2(pipe_fd[1], 1);
			close(pipe_fd[1]);
			return (0);
		}
		dup2(pipe_fd[0], 0);
	}
	if (index == parse_infos->argc - 2)
	{
		close(pipe_fd[1]);
		pipe_fd[1] = ft_open(parse_infos->argv[parse_infos->argc - 1],
				start - 1);
		if (pipe_fd[1] == -1)
		{
			close(pipe_fd[0]);
			return (0);
		}
	}
	return (1);
}

static void	child_process(int *pipe_fd, int index,
						t_parse_infos *parse_infos, int start)
{
	if (redirect_child(pipe_fd, index, parse_infos, start))
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		try_exec_cmd(parse_infos, index);
	}
	else
	{
		perror("File opening issue");
		ft_exit(EXIT_FAILURE, parse_infos);
	}
}

pid_t	exec_pipe(t_parse_infos *parse_infos, int index, int start)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("Pipe Error");
		ft_exit(EXIT_FAILURE, parse_infos);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork Error");
		ft_exit(EXIT_FAILURE, parse_infos);
	}
	if (pid == 0)
		child_process(pipe_fd, index, parse_infos, start);
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
	}
	return (pid);
}

void	parse_pipe(int argc, char **argv, char **envp)
{
	int				i;
	int				exit_code;
	t_parse_infos	*parse_infos;

	parse_infos = init_infos(argc, argv, envp, argc - 3);
	i = 2;
	while (i < argc - 1)
	{
		parse_infos->pids[i - 2] = exec_pipe(parse_infos, i, 2);
		i++;
	}
	i = 0;
	while (i < argc - 3)
	{
		waitpid(parse_infos->pids[i], &exit_code, 0);
		i++;
	}
	ft_exit(WEXITSTATUS(exit_code), parse_infos);
}
