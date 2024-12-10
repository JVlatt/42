/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:11:56 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/10 19:38:09 by mmanuell         ###   ########.fr       */
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

void	sort_loop(t_list *stack_a, t_list *stack_b)
{
	while (!check_sort_end(stack_a, stack_b))
	{
		//While Stack A Size > 3 ==> Push to Stack B
		
		//Then Push back to stack A 
	}	
}

int	get_moves_to_top(t_list *stack, int number_to_check)
{
	int		stack_position;
	int		lst_center;

	lst_center = ft_lstsize(stack) / 2;
	stack_position = ft_getlst_index(stack, number_to_check);
	if (stack_position > lst_center)
		return (stack_position - ft_lstsize(stack));
	else 
		return (stack_position);
}

int	get_moves_to_bottom(t_list *stack, int number_to_check)
{
	int		stack_position;
	int		lst_center;

	lst_center = ft_lstsize(stack) / 2;
	stack_position = ft_getlst_index(stack, number_to_check);
	if (stack_position > lst_center)
		return ((stack_position - ft_lstsize(stack)) + 1);
	else 
		return (stack_position + 1);
}

int		get_push_move_count(int number_to_check, t_list *stack_a, t_list *stack_b)
{
	int		moves_a;
	int		moves_b;
	
	moves_a = get_moves_to_top(stack_a, number_to_check);
	if (number_to_check > ft_lst_max_value(stack_b))
	{
		moves_b = get_moves_to_top(stack_b, ft_lst_max_value(stack_b));
	}
	else if (number_to_check < ft_lst_min_value(stack_b))
	{
		moves_b = get_moves_to_bottom(stack_b, ft_lst_min_value(stack_b));
	}
	else
	{
		
	}
	return (moves_a + moves_b);
}
