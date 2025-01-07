/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:26:25 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/07 15:44:00 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

pid_t	execute_fork(t_pipe *pipe)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
		ft_exit(pipe, 2, "fork", EXIT_FAILURE);
	else
		return (pid);
}

void	execute_command(t_pipe *pipe_infos, int index)
{
	//ft_printf("Input : %d \t Output : %d\n", pipe_infos->infile, pipe_infos->outfile);
	dup2(0, pipe_infos->infile);
	// dup2(1, pipe_infos->outfile);
	execve(pipe_infos->cmd_paths[index], pipe_infos->cmd_args[index], NULL);
}

void	execute_pipe(t_pipe	*pipe_infos)
{
	int		pipe_fd[2];
	pid_t	pid[pipe_infos->count];
	int		last_pipe;
	int		i;
	int		status;
	
	i = 0;
	while (i < pipe_infos->count)
	{
		pipe(pipe_fd);
		pid[i] = execute_fork(pipe_infos);
		if (pid[i] == 0)
		{
			close(pipe_fd[0]);
			if (i > 0)
				pipe_infos->infile = last_pipe;
			if (i < pipe_infos->count - 1)
				pipe_infos->outfile = pipe_fd[1];
			execute_command(pipe_infos, i);
		}
		else
		{
			i++;
			last_pipe = pipe_fd[1];
			//waitpid(pid[i], &status, 0);	
		}
	}
	i = 0;
	while (i < pipe_infos->count)
	{
		ft_printf("PID = %d\n", pid[i]);
		i++;
	}
}