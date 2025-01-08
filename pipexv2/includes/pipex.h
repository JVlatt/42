/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:34:51 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/08 22:14:51 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
#include <sys/wait.h>

//File management
int		ft_open(char *path, int mode);

//Path
char	*get_path(char **envp, char *cmd);

//Free & Error
void	ft_free_tab(char **tab);

#endif