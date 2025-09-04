/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:39:11 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/12 19:35:58 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*begin;

// 	if (!lst || !f || !del)
// 		return (NULL);
// 	begin = ft_lstnew(f(lst->content));
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		ft_lstadd_back(&begin, ft_lstnew(f(lst->content)));
// 		lst = lst->next;
// 	}
// 	return (begin);
// }
