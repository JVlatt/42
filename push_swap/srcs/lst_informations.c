/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_informations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:26:20 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/10 18:43:46 by mmanuell         ###   ########.fr       */
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

int	ft_getlst_index(t_list *lst, int value)
{
	int		index;
	t_list*	node;
	
	index = 0;
	node = lst;
	while (node)
	{
		if (node->value == value)
			return (index);
		index++;
		node = node->next;
	}
	return (-1);
}

int	ft_lst_max_value(t_list *lst)
{
	int		max;
	t_list	*node;
	
	node = lst;
	if(node)
		max = node->value;
	else
		return (0);
	while(node)
	{
		if(node->value > max)
			max = node->value;
		node = node -> next;
	}
	return (max);
}

int	ft_lst_min_value(t_list *lst)
{
	int		min;
	t_list	*node;
	
	node = lst;
	if(node)
		min = node->value;
	else
		return (0);
	while(node)
	{
		if(node->value < min)
			min = node->value;
		node = node -> next;
	}
	return (min);
}