/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:05:39 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/06 18:04:29 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*merge_path(char *env_path, char *cmd)
{
	char	*out;
	int		i;
	int		j;

	if (!cmd || !env_path)
		return (NULL);
	i = -1;
	j = 0;
	out = malloc (ft_strlen(env_path) + ft_strlen(cmd) + 2);
	while (env_path[++i])
		out[i] = env_path[i];
	out[i] = '/';
	while (cmd[j])
		out[++i] = cmd[j++];
	out[++i] = 0;
	if (access(out, F_OK) == 0)
		return (out);
	free (out);
	return (NULL);
}

char	**get_path_list(t_pipe *pipe, char **envp)
{
	char	**paths_list;
	char	*envp_path;
	int		i;

	i = 0;
	while (envp[i] && !(envp_path = ft_strnstr(envp[i], "PATH=", 5)))
		i++;
	if (!envp_path)
		ft_exit(pipe, 2, "Env Error", EXIT_FAILURE);
	paths_list = ft_split((envp_path + 5), ':');
	if (!paths_list)
		ft_exit(pipe, 2, "Split Path Error", EXIT_FAILURE);
	return (paths_list);
}
