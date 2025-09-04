/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:09 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/19 16:45:00 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_to_print_a;
	t_list	*node_to_print_b;

	node_to_print_b = *stack_b;
	node_to_print_a = *stack_a;
	while (node_to_print_a || node_to_print_b)
	{
		if (node_to_print_a)
		{
			ft_printf("%d \t", node_to_print_a->value);
			node_to_print_a = node_to_print_a->next;
		}
		else
			ft_printf(" \t");
		if (node_to_print_b)
		{
			ft_printf("%d \n", node_to_print_b->value);
			node_to_print_b = node_to_print_b->next;
		}
		else
			ft_printf(" \n");
	}
	ft_printf("_\t_\n");
	ft_printf("A\tB\n\n");
}
