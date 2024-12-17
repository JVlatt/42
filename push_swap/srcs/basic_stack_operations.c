/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:44:54 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/17 15:53:24 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_swap(t_list **stack)
{
	t_list	*tmp;

	if(ft_lstsize(*stack) >= 2)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	ft_stack_push(t_list **from, t_list **to)
{
	t_list	*tmp;
	char	new_id;
	
	if (from)
	{
		if ((*from)->stack_id == 'a')
			new_id = 'b';
		else
			new_id = 'a';
		tmp = (*from)->next;
		(*from)->next = *to;
		*to = *from;
		if (tmp)
			*from = tmp;
		else
			*from = NULL;
		(*to)->stack_id = new_id;
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	
	tmp = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = NULL;
	*stack = tmp;
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	
	ft_lstadd_front(stack, ft_lstlast(*stack));
	tmp = *stack;
	while(tmp->next != *stack)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
}