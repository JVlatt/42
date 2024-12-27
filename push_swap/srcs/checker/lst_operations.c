/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:42:35 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/27 14:13:03 by mmanuell         ###   ########.fr       */
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
	list_elem->stack_id = stackid;
	return (list_elem);
}
