/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:40:09 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/14 15:46:55 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_getenvpathlist(t_parse_infos *parse_infos)
{
	char	**paths_list;
	char	*envp_path;
	int		i;

	i = 0;
	envp_path = NULL;
	while (parse_infos->envp[i] && !envp_path)
		envp_path = ft_strnstr(parse_infos->envp[i++], "PATH=", 5);
	if (!envp_path)
	{
		perror("Env Error");
		ft_exit(EXIT_FAILURE, parse_infos);
	}
	paths_list = ft_split((envp_path + 5), ':');
	if (!paths_list)
	{
		perror("Split Path Error");
		ft_exit(EXIT_FAILURE, parse_infos);
	}
	return (paths_list);
}

char	*get_path(t_parse_infos *parse_infos, char **cmd_args)
{
	int		i;
	char	**paths_list;
	char	*tmp;
	char	*path;

	paths_list = ft_getenvpathlist(parse_infos);
	i = 0;
	while (paths_list[i])
	{
		tmp = ft_strjoin(paths_list[i], "/");
		path = ft_strjoin(tmp, cmd_args[0]);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_tab(paths_list);
			return (path);
		}
		free (path);
		i++;
	}
	perror("Path not found");
	ft_free_tab(paths_list);
	ft_free_tab(cmd_args);
	ft_exit(127, parse_infos);
	return (NULL);
}
