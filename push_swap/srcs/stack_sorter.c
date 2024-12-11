/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:11:56 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/11 19:56:25 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sort_end(t_list *stack_a, t_list *stack_b)
{
	t_list	*node;
	if(ft_lstsize(stack_b) > 0)
		return (0);
	node = stack_a;
	while (node->next)
	{
		if(node->value > node->next->value)
			return (0);
		node = node->next;	
	}
	return (1);
}
#include <stdio.h>

static void sort_two(t_list **stack_a, t_list **stack_b)
{
	t_list *node;
	printf("\n\nSort Two\n\n");
	while (ft_lstsize(*stack_b) > 0)
	{
	 	node = *stack_b;
		while (node)
		{
			node->actions = get_actions(node, *stack_b, *stack_a);
			node->actions->pa = 1;
			node = node->next;
		}
		execute_cheapest_action(stack_b, stack_a);
		//printf("Stack A Head is %d and his next is %d \n", (*stack_a)->value, (*stack_a)->next->value);
	}
}

void sort_loop(t_list **stack_a, t_list **stack_b)
{
	// while (!check_sort_end(stack_a, stack_b))
	// {
	// 	//While Stack A Size > 3 ==> Push to Stack B

	// 	//Then Push back to stack A
	// }
	t_list *node;
	while (ft_lstsize(*stack_a) > 3)
	{
	 	node = *stack_a;
		while (node)
		{
			node->actions = get_actions(node, *stack_a, *stack_b);
			node->actions->pb = 1;
			node = node->next;
		}
		execute_cheapest_action(stack_a, stack_b);
	}
	t_list *max_value_b;

	max_value_b = ft_lst_max_value(*stack_b);
	max_value_b->actions = get_actions(max_value_b, *stack_b, NULL);
	execute_node_action(stack_a, stack_b, max_value_b);
	ft_reverse_rotate(stack_a);
	ft_print_stacks(stack_a, stack_b);
	sort_two(stack_a, stack_b);
}


