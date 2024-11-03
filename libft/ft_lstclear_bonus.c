/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:58:25 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/03 21:11:54 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **begin, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*todel;

	todel = *begin;
	while (todel)
	{
		tmp = todel->next;
		del(todel->content);
		free(todel);
		todel = tmp;
	}
	begin = NULL;
}
