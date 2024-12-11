/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:42:30 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/11 18:53:16 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int     			value;
    struct s_list  		*next;
	struct s_actions	*actions;
	char				stack_id;
}   t_list;

typedef struct s_actions
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
} t_actions;

//  Parser

t_list  *parse_args(int argc, char **args);

//  Stack Custom Operations 

void	ft_lstadd_back(t_list **lst, t_list *new_elem);
void	ft_lstadd_front(t_list **begin_list, t_list *new);
t_list	*ft_lstnew(int value, char stackid);
void	ft_lstclear(t_list **lst);

//	Stack Base Operations

void	ft_stack_swap(t_list **stack);
void	ft_stack_push(t_list **from, t_list **to);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);

//	Stack Informations

t_list	*ft_lstlast(t_list	*lst);
int	    ft_lstsize(t_list *lst);
int		ft_getlst_index(t_list *lst, t_list *node_to_find);
t_list	*ft_lst_min_value(t_list *lst);
t_list	*ft_lst_max_value(t_list *lst);

//	Pre-Calculation
t_actions	*get_actions(t_list *node_to_move, t_list *stack_a, t_list *stack_b);

//	Solver
void	sort_loop(t_list **stack_a, t_list **stack_b);
void	execute_cheapest_action(t_list **source_stack, t_list **dest_stack);
void	execute_node_action(t_list **stack_a, t_list **stack_b, t_list *node);

//	Utils

int     ft_strcmp(char *s1, char *s2);

//	Debug

void	ft_print_actions(t_list *node);
void    ft_print_stacks(t_list **stack_a, t_list **stack_b);

#endif