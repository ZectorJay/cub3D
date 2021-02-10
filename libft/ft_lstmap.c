/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:05:41 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/21 01:45:34 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*header;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(lst->content);
	f(new->content);
	header = new;
	while (lst->next)
	{
		if (!f(lst->content))
			ft_lstdelone(lst, del);
		new->next = lst->next;
		lst = lst->next;
	}
	return (header);
}
