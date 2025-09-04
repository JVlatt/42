/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_sorter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:30:36 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/19 16:31:53 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || ft_lstsize(*stack) != 3)
		return ;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && third < first)
		execute_rotate('a', stack, NULL);
	else if (first < second && second > third && third < first)
		execute_reverse_rotate('a', stack, NULL);
	else if (first > second && second < third && third > first)
		execute_swap('a', stack, NULL);
	else if (first < second && second > third && third > first)
	{
		execute_swap('a', stack, NULL);
		execute_rotate('a', stack, NULL);
	}
	else if (first > second && second > third)
	{
		execute_swap('a', stack, NULL);
		execute_reverse_rotate('a', stack, NULL);
	}
}
