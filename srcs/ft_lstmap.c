/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbalart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:59:45 by vbalart           #+#    #+#             */
/*   Updated: 2016/11/10 20:15:55 by vbalart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp2;

	if (f == NULL || lst == NULL)
		return (NULL);
	tmp = (*f)(lst);
	if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	lst = lst->next;
	tmp2 = new;
	while (lst)
	{
		tmp = (*f)(lst);
		if ((tmp2->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		lst = lst->next;
		tmp2 = tmp2->next;
	}
	return (new);
}
