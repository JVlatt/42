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

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	char	**cmd_paths;
	char	**cmd_args;
}	t_pipe;

// Args Parser
t_pipe	*parse_args(int argc, char **args);

// Free & Errors Management
void	ft_free_pipe(t_pipe *pipe, int code);

#endif