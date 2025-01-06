/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:54:30 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/24 14:57:15 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
char	*merge_path(char *env_path, char * cmd)
{
	char	*out;
	int		i;
	int		j;

	i = -1;
	j = 0;
	out = malloc (ft_strlen(env_path) + ft_strlen(cmd) + 2);
	while (env_path[++i])
		out[i] = env_path[i];
	out[i] = '/';
	while (cmd[j])
		out[++i] = cmd[j++];
	out[++i] = 0;
	ft_printf("%s\n", out);
	if (access(out, F_OK) == 0)
		return (out);
	free (out);
	return (NULL);
}

void	ft_exit(t_pipe *pipe, int code, char *msg, int exitcode)
{
	ft_free_pipe(pipe, code);
	if (exitcode == 1)
		perror(msg);
	exit(exitcode);
}

void	ft_free_tab(int size, char **tab)
{
	int i;

	if (size > 0)
	{
		i = size - 1;
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
	}
	else
	{
		i = 0;
		while(tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

void	ft_free_pipe(t_pipe *pipe, int code)
{
	if (code >= 2)
	{
		ft_free_tab(pipe->count, pipe->cmd_paths);
	}
	if (code >= 1)
	{
		ft_free_tab(pipe->count, pipe->cmd_args);
	}
	if (code >= 0)
	{
		free(pipe);
	}
}
