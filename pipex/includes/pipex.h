/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:34:51 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/15 14:50:35 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_parse_infos
{
	char	**argv;
	char	**envp;
	int		argc;
	pid_t	*pids;
}	t_parse_infos;

//File management
int				ft_open(char *path, int mode);

//Path
char			*get_path(t_parse_infos *parse_infos, char **cmd_args);

// Pipe & here_doc
void			parse_pipe(int argc, char **argv, char **envp);
void			parse_here_doc(int argc, char **argv, char **envp);
pid_t			exec_pipe(t_parse_infos *parse_infos, int index, int start);

//Init, Free & Error
t_parse_infos	*init_infos(int argc, char **argv, char **envp, int pid_count);
void			ft_free_tab(char **tab);
void			ft_exit(int exitcode, t_parse_infos *parse_infos);

#endif