/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:50:54 by nakoo             #+#    #+#             */
/*   Updated: 2022/07/18 17:08:31 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;

	ret = ft_lstnew(f(lst->content));
	if (!ret)
		return (0);
	cur = ret;
	lst = lst->next;
	while (lst)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (!(cur->next))
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (ret);
}
