/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:13:27 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/29 11:21:31 by Olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	n_list = ft_lstnew((*f)(lst->content));
	if (!n_list)
		return (NULL);
	save = n_list;
	lst = lst->next;
	while (lst)
	{
		n_list->next = ft_lstnew(f(lst->content));
		if (!n_list->content)
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		n_list = n_list->next;
		lst = lst->next;
	}
	n_list->next = NULL;
	return (save);
}
