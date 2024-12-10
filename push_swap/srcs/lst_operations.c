/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:42:35 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/10 17:27:17 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list	*end;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_elem;
		return ;
	}
	end = ft_lstlast(*lst);
	end->next = new_elem;
}

void	ft_lstadd_front(t_list **begin_list, t_list *new)
{
	if (new)
	{
		new->next = *begin_list;
		*begin_list = new;
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*list_elem;

	list_elem = malloc(sizeof (t_list));
	if (!list_elem)
		return (NULL);
	list_elem->value = value;
	list_elem->next = NULL;
	return (list_elem);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
