/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:54:30 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/06 19:53:55 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(t_pipe *pipe, int code, char *msg, int exitcode)
{
	ft_free_pipe(pipe, code);
	if (exitcode == 1)
		perror(msg);
	exit(exitcode);
}

void	ft_free_tab(int size, char **tab)
{
	int i;

	if (size > 0)
	{
		i = size - 1;
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
	}
	else
	{
		i = 0;
		while(tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

void	ft_free_pipe(t_pipe *pipe, int code)
{
	int	i;

	i = 0;
	if (code >= 2)
	{
		ft_free_tab(pipe->count, pipe->cmd_paths);
	}
	if (code >= 1)
	{
		while (i < pipe->count)
		{
			ft_free_tab(pipe->count, pipe->cmd_args[i]);
			i++;			
		}
		free(pipe->cmd_args);
	}
	if (code >= 0)
	{
		free(pipe);
	}
}

void	ft_print_pipe_infos(t_pipe *pipe)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	ft_printf("Input : %d \t Output : %d\n", pipe->infile, pipe->outfile);
	ft_printf("Commands : %d \n", pipe->count);
	while (i < pipe->count)
	{
		j = 0;
		ft_printf("%d - \t %s \t", i, pipe->cmd_paths[i]);
		while (pipe->cmd_args[i][j])
		{
			ft_printf("%d:%s ", j, pipe->cmd_args[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	ft_isemptystr(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 9 && *str <= 13) || *str == 32))
			return (0);
		str++;
	}
	return (1);
}
