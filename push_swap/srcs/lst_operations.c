/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:42:35 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/15 16:14:59 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
