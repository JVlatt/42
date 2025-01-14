/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:42:15 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/14 17:15:59 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	get_here_doc(char *limiter)
{
	int		here_doc_fd;
	char	*line;
	
	here_doc_fd = ft_open("here_doc", 2);
	if (!here_doc_fd)
	{
		perror("File opening issue");
		exit(EXIT_FAILURE);
	}
	while (ft_strcmp(line, ft_strjoin(limiter, "\n")) != 0)
	{
		write(1, "HERE_DOC >>", 11);
		line = get_next_line(0);
		write(here_doc_fd, line, ft_strlen(line));
	}
	close(here_doc_fd);
}

void	parse_here_doc(int argc, char **argv, char **envp)
{
	int i;
	int exit_code;
	int	in_fd;
	t_parse_infos *parse_infos;

	parse_infos = init_infos(argc, argv, envp, argc - 4);
	get_here_doc(argv[2]);
	i = 3;
	while (i < argc - 1)
	{
		parse_infos->pids[i - 3] = exec_pipe(parse_infos, i, 3);
		i++;
	}
	i = 0;
	while (i < argc - 4)
	{
		waitpid(parse_infos->pids[i], &exit_code, 0);
		i++;
	}
	unlink(argv[1]);
	ft_exit(WEXITSTATUS(exit_code), parse_infos);
}
