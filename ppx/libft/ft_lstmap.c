/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:06:06 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/08 15:20:44 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_list(t_list *new_list, t_list *lst, void *(*f)(void *),
		void(del)(void *))
{
	void	*content;

	while (lst)
	{
		content = f(lst->content);
		new_list->next = ft_lstnew(content);
		if (!new_list->next)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return ;
		}
		lst = lst->next;
		new_list = new_list->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(del)(void *))
{
	t_list	*new_head;
	void	*content;

	if (!lst || !f || !del)
	{
		return (NULL);
	}
	content = f(lst->content);
	new_head = ft_lstnew(content);
	if (!new_head)
	{
		del(content);
		return (NULL);
	}
	lst = lst->next;
	ft_fill_list(new_head, lst, f, del);
	return (new_head);
}
