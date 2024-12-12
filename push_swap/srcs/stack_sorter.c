/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:11:56 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/12 16:58:11 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list *node;
	
	while (ft_lstsize(*stack_b) > 0)
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
	t_list *node;
	
	node = *stack_a;
	while (node->next)
	{
		if(node->value > node->next->value)
		{
			if (node == *stack_a)
			{
				ft_stack_swap(stack_a);
				write(1,"sa\n",3);
			}
			else
			{
				ft_reverse_rotate(stack_a);
				write(1,"rra\n",4);
			}
			node = *stack_a;
		}
		node = node->next;
	}
}
void 	sort_b(t_list **stack_b)
{
	t_list *max_value_b;

	max_value_b = ft_lst_max_value(*stack_b);
	max_value_b->actions = get_actions(max_value_b, *stack_b, NULL, -1);
	execute_node_action(stack_b, NULL, max_value_b);
}

void push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list *node;

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
	push_to_b(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
	sort_b(stack_b);
	ft_print_stacks(stack_a, stack_b);
	sort_a(stack_a);
	ft_print_stacks(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
}


