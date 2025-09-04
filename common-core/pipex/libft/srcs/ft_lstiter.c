/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:34:25 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/19 16:23:55 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *begin, void (*f)(void *))
{
	t_list	*tmpnode;

	tmpnode = begin;
	while (tmpnode)
	{
		f(tmpnode);
		tmpnode = tmpnode->next;
	}
}
