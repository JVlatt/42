/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:36:31 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 15:25:32 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker/checker.h"

int	execute_swap(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_stack_swap(stack_a);
		return (1);
	}
	else if (arg == 'b')
	{
		ft_stack_swap(stack_b);
		return (1);
	}
	else if (arg == 's')
	{
		ft_stack_swap(stack_a);
		ft_stack_swap(stack_b);
		return (1);
	}
	return (0);
}

int	execute_push(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_stack_push(stack_b, stack_a);
		return (1);
	}
	else if (arg == 'b')
	{
		ft_stack_push(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	execute_rotate(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_rotate(stack_a);
		return (1);
	}
	else if (arg == 'b')
	{
		ft_rotate(stack_b);
		return (1);
	}
	else if (arg == 'r')
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		return (1);
	}
	return (0);
}

int	execute_reverse_rotate(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_reverse_rotate(stack_a);
		return (1);
	}
	else if (arg == 'b')
	{
		ft_reverse_rotate(stack_b);
		return (1);
	}
	else if (arg == 'r')
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		return (1);
	}
	return (0);
}
