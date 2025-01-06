/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:15:22 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/06 19:54:48 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipe	*init_pipe(int argc)
{
	t_pipe	*pipe;

	pipe = malloc(sizeof(t_pipe));
	if (!pipe)
		ft_exit(pipe, -1, "Malloc Error", EXIT_FAILURE);
	pipe->cmd_args = ft_calloc(sizeof(char **), argc - 2);
	if (!pipe->cmd_args)
		ft_exit(pipe, 0, "Malloc Error", EXIT_FAILURE);
	pipe->cmd_paths = ft_calloc(sizeof(char *), argc - 2);
	if (!pipe->cmd_paths)
		ft_exit(pipe, 1, "Malloc Error", EXIT_FAILURE);
	pipe->count = 0;
	return (pipe);
}

void	get_files(t_pipe *pipe, char *file1, char *file2)
{
	int	infd;
	int	outfd;

	infd = open(file1, O_RDONLY, 0777);
	if (infd == -1)
		ft_exit(pipe, -1, "Infile Error", EXIT_FAILURE);
	outfd = open(file2, O_WRONLY | O_CREAT, 0644);
	if (outfd == -1)
		ft_exit(pipe, -1, "Infile Error", EXIT_FAILURE);
	pipe->infile = infd;
	pipe->outfile = outfd;
}

void	get_paths(t_pipe *pipe, char **envp)
{
	int		i;
	int		j;
	char	**paths_list;
	char	*path;

	paths_list = get_path_list(pipe, envp);
	i = 0;
	while (i < pipe->count)
	{
		j = 0;
		while ((path = merge_path(paths_list[j], pipe->cmd_paths[i])) == NULL)
		{
			j++;
			if (!paths_list[j])
				ft_exit(pipe, 2, "Env Error", EXIT_FAILURE);
		}
		free(pipe->cmd_paths[i]);
		pipe->cmd_paths[i] = path;
		i++;
	}
	ft_free_tab(0, paths_list);
}

void	get_commands(t_pipe *pipe, char **commands, int argc)
{
	char	**split_cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (ft_isemptystr(commands[i]))
			ft_exit(pipe, 2, "Empty Argument", EXIT_FAILURE);
		pipe->cmd_args[i] = ft_split(commands[i], ' ');
		if (!pipe->cmd_args[i])
			ft_exit(pipe, 2, "Split Error", EXIT_FAILURE);
		pipe->cmd_paths[i] = ft_strdup(pipe->cmd_args[i][0]);
		i++;
		pipe->count = i;
	}
}

t_pipe	*parse_args(int argc, char **args, char **envp)
{
	t_pipe	*pipe;

	pipe = init_pipe(argc);
	get_files(pipe, args[0], args[argc - 1]);
	args++;
	get_commands(pipe, args, argc - 2);
	get_paths(pipe, envp);
	return (pipe);
}
