/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:20:34 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/06 11:32:07 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_cmd *cmd)
{
	char	buf[PATH_MAX + 1];

	ft_bzero(buf, sizeof(buf));
	if (!getcwd(buf, sizeof(buf)))
	{
		perror("minishell: pwd");
		return (1);
	}
	ft_printf_fd(cmd->fd_out, "%s\n", &buf[0]);
	return (0);
}

int	ft_exit(t_cmd *cmd, t_data *data)
{
	if (!data->is_child)
		ft_putstr("exit\n", 2);
	else
	{
		close(cmd->fd_in);
		close(cmd->fd_out);
	}
	if (cmd && cmd->argc > 1)
	{
		if (ft_isint(cmd->args[1]))
		{
			ft_putstr("minishell: exit: ", 2);
			ft_putstr(cmd->args[1], 2);
			ft_putstr(": numeric argument required\n", 2);
			data->exit_code = 2;
		}
		else if (cmd->argc > 2)
		{
			ft_putstr("minishell: exit: too many arguments\n", 2);
			return (1);
		}
	}
	ft_kill(cmd, data);
	return (0);
}
