/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:05:51 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/27 14:16:41 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:42:30 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/19 17:11:11 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line.h"

//  Parser
t_list		*parse_args(int argc, char **args);
t_list		*parse_string(char *str);

//  List Init & clear 
t_list		*ft_lstnew(int value, char stackid);
void		delete_node_content(t_list *node);

// 	Execute Actions 
void		execute_swap(char arg, t_list **stack_a, t_list **stack_b);
void		execute_push(char arg, t_list **stack_a, t_list **stack_b);
void		execute_rotate(char arg, t_list **stack_a, t_list **stack_b);
void		execute_reverse_rotate(char arg,
				t_list **stack_a,
				t_list **stack_b);

//	Stack Base Operations
void		ft_stack_swap(t_list **stack);
void		ft_stack_push(t_list **from, t_list **to);
void		ft_rotate(t_list **stack);
void		ft_reverse_rotate(t_list **stack);

//	Stack Informations
t_list		*ft_lstlast(t_list	*lst);
int			ft_lstsize(t_list *lst);
int			ft_getlst_index(t_list *lst, t_list *node_to_find);
t_list		*ft_lst_min_value(t_list *lst);
t_list		*ft_lst_max_value(t_list *lst);

//	Debug
void		ft_print_actions(t_list *node);
void		ft_print_stacks(t_list **stack_a, t_list **stack_b);

#endif