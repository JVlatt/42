/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:36:31 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/27 14:09:51 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker/checker.h"

void	execute_swap(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_stack_swap(stack_a);
	}
	else if (arg == 'b')
	{
		ft_stack_swap(stack_b);
	}
	else if (arg == 's')
	{
		ft_stack_swap(stack_a);
		ft_stack_swap(stack_b);
	}
}

void	execute_push(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_stack_push(stack_b, stack_a);
	}
	else if (arg == 'b')
	{
		ft_stack_push(stack_a, stack_b);
	}
}

void	execute_rotate(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_rotate(stack_a);
	}
	else if (arg == 'b')
	{
		ft_rotate(stack_b);
	}
	else if (arg == 'r')
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

void	execute_reverse_rotate(char arg, t_list **stack_a, t_list **stack_b)
{
	if (arg == 'a')
	{
		ft_reverse_rotate(stack_a);
	}
	else if (arg == 'b')
	{
		ft_reverse_rotate(stack_b);
	}
	else if (arg == 'r')
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}
