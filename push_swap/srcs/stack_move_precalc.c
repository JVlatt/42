#include "../includes/push_swap.h"

static void	get_moves_to_top(t_actions *actions, t_list *node_to_move, t_list *stack, char stack_id)
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

static void	get_moves_to_bottom(t_actions *actions, t_list *node_to_move, t_list *stack, char stack_id)
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
#include <stdio.h>
static t_list	*get_biggest_inferior_value(t_list *stack, int value)
{
	t_list	*tmp;
	t_list	*max_inferior_node;

	tmp = stack;
	max_inferior_node = ft_lst_min_value(stack);
	while (tmp)
	{
		if	(value > tmp->value && max_inferior_node->value < tmp->value)
		{
			max_inferior_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_inferior_node);
}
static t_actions	*optimize_actions(t_actions *actions)
{
	while (actions->sa > 0 && actions->sb > 0)
	{
		actions->sa--;
		actions->sb--;
		actions->ss++;
	}
	while (actions->ra > 0 && actions->rb > 0)
	{
		actions->ra--;
		actions->rb--;
		actions->rr++;
	}
	while (actions->rra > 0 && actions->rrb > 0)
	{
		actions->rra--;
		actions->rrb--;
		actions->rrr++;
	}
	return (actions);
}

t_actions	*get_actions(t_list *node_to_move, t_list *stack_source, t_list *stack_dest, int sort_order)
{
	t_actions *actions;
	size_t n;
	int i;

	if (node_to_move->actions)
		free(node_to_move->actions);
	i = 0;
	n = sizeof(t_actions);
	actions = malloc(sizeof(t_actions));
	if (!actions)
		return (NULL);
	while (n--)
	{
		((char *)actions)[i] = 0;
		i++;
	}
	if (stack_source)
		get_moves_to_top(actions, node_to_move, stack_source, stack_source->stack_id);
	if (stack_dest)
	{
		if (sort_order < 0)
		{
			if (node_to_move->value > ft_lst_max_value(stack_dest)->value)
				get_moves_to_top(actions, ft_lst_max_value(stack_dest), stack_dest, stack_dest->stack_id);
			else if (node_to_move->value < ft_lst_min_value(stack_dest)->value)
				get_moves_to_bottom(actions, ft_lst_min_value(stack_dest), stack_dest, stack_dest->stack_id);
			else
				get_moves_to_top(actions, get_biggest_inferior_value(stack_dest, node_to_move->value), stack_dest, stack_dest->stack_id);
		}
		else
		{
			if (node_to_move->value > ft_lst_max_value(stack_dest)->value)
				get_moves_to_bottom(actions, ft_lst_max_value(stack_dest), stack_dest, stack_dest->stack_id);
			else if (node_to_move->value < ft_lst_min_value(stack_dest)->value)
				get_moves_to_top(actions, ft_lst_min_value(stack_dest), stack_dest, stack_dest->stack_id);
			else
				get_moves_to_bottom(actions, get_biggest_inferior_value(stack_dest, node_to_move->value), stack_dest, stack_dest->stack_id);
		}
		
	}
	return (optimize_actions(actions));
}