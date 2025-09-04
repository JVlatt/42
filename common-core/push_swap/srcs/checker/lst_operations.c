/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:42:35 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/20 16:11:37 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker/checker.h"

void	delete_node_content(t_list *node)
{
	free(node->actions);
}

t_list	*ft_lstnew(int value, char stackid)
{
	t_list	*list_elem;

	list_elem = malloc(sizeof (t_list));
	if (!list_elem)
		return (NULL);
	list_elem->value = value;
	list_elem->next = NULL;
	list_elem->actions = NULL;
	list_elem->stack_id = stackid;
	return (list_elem);
}

int	is_sorted(t_list *stack)
{
	t_list	*node;

	node = stack;
	while (node->next)
	{
		if (node->value > node->next->value)
		{
			return (0);
		}
		node = node->next;
	}
	return (1);
}

int	check_result(t_list *stack_a, t_list *stack_b)
{
	if (stack_b)
	{
		ft_lstclear(&stack_b, &delete_node_content);
		return (0);
	}
	return (is_sorted(stack_a));
}
