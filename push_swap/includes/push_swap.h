/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:42:30 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/10 19:36:04 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int     value;
    struct s_list  *next;
    struct s_list  *prev;
}   t_list;

//  Parser

t_list  *parse_args(int argc, char **args);

//  Stack Custom Operations 

void	ft_lstadd_back(t_list **lst, t_list *new_elem);
void	ft_lstadd_front(t_list **begin_list, t_list *new);
t_list	*ft_lstnew(int value);
void	ft_lstclear(t_list **lst);

//	Stack Base Operations

void	ft_stack_swap(t_list **stack);
void	ft_stack_push(t_list **from, t_list **to);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);

//	Stack Informations

void    ft_print_stacks(t_list *stack_a, t_list *stack_b);
int		ft_lst_max_value(t_list *lst);
int		ft_lst_min_value(t_list *lst);
t_list	*ft_lstlast(t_list	*lst);
int	    ft_lstsize(t_list *lst);
int		ft_getlst_index(t_list *lst, int value);
int		ft_lst_min_value(t_list *lst);
int		ft_lst_max_value(t_list *lst);

#endif