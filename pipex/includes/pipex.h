/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:34:51 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/06 19:52:07 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	char	**cmd_paths;
	char	***cmd_args;
	int		count;
}	t_pipe;

// Args Parser
t_pipe	*parse_args(int argc, char **args, char **envp);
char	*merge_path(char *env_path, char *cmd);
char	**get_path_list(t_pipe *pipe, char **envp);

// Init, Free & Errors Management
int		ft_isemptystr(char *str);
void	ft_exit(t_pipe *pipe, int code, char *msg, int exitcode);
void	ft_free_tab(int size, char **tab);
void	ft_free_pipe(t_pipe *pipe, int code);

// Debug
void	ft_print_pipe_infos(t_pipe *pipe);

#endif