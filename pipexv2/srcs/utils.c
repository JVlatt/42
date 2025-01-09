/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:01 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/09 21:14:24 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_getenvpathlist(char **envp)
{
	char	**paths_list;
	char	*envp_path;
	int		i;

	i = 0;
	while (envp[i] && !(envp_path = ft_strnstr(envp[i], "PATH=", 5)))
		i++;
	if (!envp_path)
	{
		perror("Env Error");
		exit(EXIT_FAILURE);
	}
	paths_list = ft_split((envp_path + 5), ':');
	if (!paths_list)
	{
		perror("Split Path Error");
		exit(EXIT_FAILURE);
	}
	return (paths_list);
}

char	*get_path(char **env_paths, char *cmd)
{
	int		i;
	char	**paths_list;
	char	*tmp;
	char	*path;

	paths_list = ft_getenvpathlist(env_paths);
	i = 0;
	while (paths_list[i])
	{	
		tmp = ft_strjoin(paths_list[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_tab(paths_list);
			return (path);
		}
		free (path);
		i++;
	}
	ft_free_tab(paths_list);
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_open(char *path, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(path, O_RDONLY, 0777);
	else if (mode == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("File opening issue");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

