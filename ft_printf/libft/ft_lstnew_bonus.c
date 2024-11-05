/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:17:02 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/03 21:13:42 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_elem;

	list_elem = malloc(sizeof (t_list *));
	if (!list_elem)
		return (NULL);
	list_elem->content = content;
	list_elem->next = NULL;
	return (list_elem);
}
