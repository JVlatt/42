/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_precalc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:48:07 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/15 16:11:12 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_actions	*init_actions(t_list *node)
{
	int			i;
	size_t		n;
	t_actions	*actions;

	if (node->actions)
		free(node->actions);
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
	return (actions);
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

t_actions	*get_actions(t_list *node_to_move, t_list *stack_source,
			t_list *stack_dest, int sort_order)
{
	t_actions	*actions;

	actions = init_actions(node_to_move);
	if (stack_source)
		get_moves_to_top(actions, node_to_move,
			stack_source, stack_source->stack_id);
	if (stack_dest)
	{
		if (sort_order < 0)
			get_moves_decr(actions, node_to_move, stack_source, stack_dest);
		else
			get_moves_incr(actions, node_to_move, stack_source, stack_dest);
	}
	return (optimize_actions(actions));
}
