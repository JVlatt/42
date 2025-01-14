/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:01 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/14 16:22:04 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_open(char *path, int mode)
{
	int	fd;

	fd = -1;
	if (mode == 0)
		fd = open(path, O_RDONLY, 0777);
	else if (mode == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (mode == 2)
		fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0777);
	return (fd);
}

t_parse_infos	*init_infos(int argc, char **argv, char **envp, int pid_count)
{
	t_parse_infos	*parse_infos;

	parse_infos = malloc(sizeof(t_parse_infos));
	if (!parse_infos)
	{
		perror("Malloc struct error");
		exit(1);
	}
	parse_infos->pids = malloc(sizeof(pid_t) * (pid_count));
	if (!parse_infos->pids)
	{
		perror("Malloc pids error");
		free(parse_infos);
		exit(1);
	}
	parse_infos->argc = argc;
	parse_infos->argv = argv;
	parse_infos->envp = envp;
	return (parse_infos);
}

void	ft_exit(int exitcode, t_parse_infos *parse_infos)
{
	free(parse_infos->pids);
	free(parse_infos);
	exit(exitcode);
}
