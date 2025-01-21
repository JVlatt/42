/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:07:32 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 18:45:45 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker/checker.h"
#include <limits.h>

static int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9')
			&& *str != '-' && *str != '+')
			return (0);
		if (*str == '-' || *str == '+')
		{
			str++;
			if (*str >= '0' && *str <= '9')
				return (ft_isnum(str));
			else
				return (0);
		}
		str++;
	}
	return (1);
}

static int	is_valid_arg(t_list *head, char *arg)
{
	t_list	*node;

	if (!ft_isnum(arg))
		return (0);
	if (ft_strlen(arg) > 11)
		return (0);
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (0);
	node = head;
	while (node)
	{
		if (node->value == ft_atoi(arg))
			return (0);
		node = node->next;
	}
	return (1);
}

t_list	*parse_string(char *str)
{
	char	**args;
	int		argc;
	t_list	*arg_list;

	args = ft_split(str, ' ');
	argc = 0;
	while (args[argc])
		argc++;
	arg_list = parse_args(argc, args);
	argc--;
	while (argc >= 0)
	{
		free(args[argc]);
		argc--;
	}
	free(args);
	return (arg_list);
}

t_list	*parse_args(int argc, char **args)
{
	t_list	*arg_list;
	int		i;

	i = 0;
	arg_list = NULL;
	while (i < argc)
	{
		if (is_valid_arg(arg_list, args[i]))
		{
			if (!arg_list)
				arg_list = ft_lstnew(ft_atoi(args[i]), 'a');
			else
				ft_lstadd_back(&arg_list, ft_lstnew(ft_atoi(args[i]), 'a'));
		}
		else
		{
			ft_lstclear(&arg_list, &delete_node_content);
			write(2, "Error\n", 6);
			return (NULL);
		}
		i++;
	}
	return (arg_list);
}
