/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:34:51 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/24 14:58:01 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	char	**cmd_paths;
	char	**cmd_args;
	int		count;
}	t_pipe;

// Args Parser
t_pipe	*parse_args(int argc, char **args, char **envp);
char	*merge_path(char *env_path, char * cmd);

// Init, Free & Errors Management
void	ft_exit(t_pipe *pipe, int code, char *msg, int exitcode);
void	ft_free_tab(int size, char **tab);
void	ft_free_pipe(t_pipe *pipe, int code);
#endif