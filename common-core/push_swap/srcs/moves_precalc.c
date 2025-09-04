/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_precalc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:44 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/21 19:02:26 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_moves_to_top(t_actions *actions, t_list *node_to_move,
			t_list *stack, char stack_id)
{
	int		stack_position;
	int		lst_center;

	if (ft_getlst_index(stack, node_to_move) == 0)
		return ;
	lst_center = ft_lstsize(stack) / 2;
	stack_position = ft_getlst_index(stack, node_to_move);
	if (stack_position > lst_center)
	{
		if (stack_id == 'a')
			actions->rra = ft_lstsize(stack) - stack_position;
		else if (stack_id == 'b')
			actions->rrb = ft_lstsize(stack) - stack_position;
	}
	else
	{
		if (stack_id == 'a')
			actions->ra = stack_position;
		else if (stack_id == 'b')
			actions->rb = stack_position;
	}
}

static void	get_moves_to_bottom(t_actions *actions, t_list *node_to_move,
			t_list *stack, char stack_id)
{
	int		stack_position;
	int		lst_center;

	if (ft_getlst_index(stack, node_to_move) == ft_lstsize(stack) - 1)
		return ;
	lst_center = ft_lstsize(stack) / 2;
	stack_position = ft_getlst_index(stack, node_to_move);
	if (stack_position > lst_center)
	{
		if (stack_id == 'a')
			actions->rra = ft_lstsize(stack) - stack_position - 1;
		else if (stack_id == 'b')
			actions->rrb = ft_lstsize(stack) - stack_position - 1;
	}
	else
	{
		if (stack_id == 'a')
			actions->ra = stack_position + 1;
		else if (stack_id == 'b')
			actions->rb = stack_position + 1;
	}
}

static t_list	*get_biggest_inferior_value(t_list *stack, int value)
{
	t_list	*tmp;
	t_list	*max_inferior_node;

	tmp = stack;
	max_inferior_node = ft_lst_min_value(stack);
	while (tmp)
	{
		if (value > tmp->value && max_inferior_node->value < tmp->value)
		{
			max_inferior_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_inferior_node);
}

void	get_moves_incr(t_actions *actions, t_list *node_to_move,
			t_list *stack_dest)
{
	if (node_to_move->value > ft_lst_max_value(stack_dest)->value)
		get_moves_to_bottom(actions, ft_lst_max_value(stack_dest),
			stack_dest, stack_dest->stack_id);
	else if (node_to_move->value < ft_lst_min_value(stack_dest)->value)
		get_moves_to_top(actions, ft_lst_min_value(stack_dest),
			stack_dest, stack_dest->stack_id);
	else
		get_moves_to_bottom(actions,
			get_biggest_inferior_value(stack_dest, node_to_move->value),
			stack_dest, stack_dest->stack_id);
}

void	get_moves_decr(t_actions *actions, t_list *node_to_move,
			t_list *stack_dest)
{
	if (node_to_move->value > ft_lst_max_value(stack_dest)->value)
		get_moves_to_top(actions, ft_lst_max_value(stack_dest),
			stack_dest, stack_dest->stack_id);
	else if (node_to_move->value < ft_lst_min_value(stack_dest)->value)
		get_moves_to_bottom(actions, ft_lst_min_value(stack_dest),
			stack_dest, stack_dest->stack_id);
	else
		get_moves_to_top(actions,
			get_biggest_inferior_value(stack_dest, node_to_move->value),
			stack_dest, stack_dest->stack_id);
}
