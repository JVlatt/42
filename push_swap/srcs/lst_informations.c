/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_informations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:26:20 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/19 16:37:43 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstlast(t_list	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = lst;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	ft_getlst_index(t_list *lst, t_list *node_to_find)
{
	int		index;
	t_list	*node;

	index = 0;
	node = lst;
	while (node)
	{
		if (node == node_to_find)
			return (index);
		index++;
		node = node->next;
	}
	return (-1);
}

t_list	*ft_lst_max_value(t_list *lst)
{
	t_list	*max;
	t_list	*node;

	node = lst;
	max = node;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node -> next;
	}
	return (max);
}

t_list	*ft_lst_min_value(t_list *lst)
{
	t_list	*min;
	t_list	*node;

	node = lst;
	min = node;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node -> next;
	}
	return (min);
}
