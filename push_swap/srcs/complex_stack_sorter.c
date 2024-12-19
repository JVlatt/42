/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_stack_sorter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:11:56 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/19 16:45:55 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	while (*stack_b)
	{
		node = *stack_b;
		while (node)
		{
			node->actions = get_actions(node, *stack_b, *stack_a, 1);
			node->actions->pa = 1;
			node = node->next;
		}
		execute_cheapest_action(stack_b, stack_a);
	}
}

void	sort_a(t_list **stack_a)
{
	t_list	*min_value_a;

	min_value_a = ft_lst_min_value(*stack_a);
	min_value_a->actions = get_actions(min_value_a, *stack_a, NULL, 1);
	execute_node_action(stack_a, NULL, min_value_a);
}

void	sort_b(t_list **stack_b)
{
	t_list	*max_value_b;

	max_value_b = ft_lst_max_value(*stack_b);
	max_value_b->actions = get_actions(max_value_b, *stack_b, NULL, -1);
	execute_node_action(stack_b, NULL, max_value_b);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	while (ft_lstsize(*stack_a) > 3)
	{
		node = *stack_a;
		while (node)
		{
			node->actions = get_actions(node, *stack_a, *stack_b, -1);
			node->actions->pb = 1;
			node = node->next;
		}
		execute_cheapest_action(stack_a, stack_b);
	}
}

void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	execute_push('b', stack_a, stack_b);
	execute_push('b', stack_a, stack_b);
	push_to_b(stack_a, stack_b);
	sort_b(stack_b);
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	sort_a(stack_a);
}
