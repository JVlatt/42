/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:54:30 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/24 14:57:15 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_pipe(t_pipe *pipe, int code)
{
	if (code >= 2)
	{
		free(pipe->cmd_paths);
	}
	if (code >= 1)
	{
		free(pipe->cmd_args);
	}
	if (code >= 0)
	{
		free(pipe);
	}
}