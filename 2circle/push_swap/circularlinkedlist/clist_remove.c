/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:38:13 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/19 15:20:18 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_linked_list.h"

int	clist_remove(t_clist **clist)
{
	t_node	*r_node;
	int		r_data;

	r_node = (*clist)->top;
	r_data = r_node->data;
	if ((*clist)->top == (*clist)->top->next)
	{
		clist_init(clist);
		free(r_node);
		r_node = NULL;
		return (r_data);
	}
	(*clist)->top = (*clist)->before;
	(*clist)->before = (*clist)->bottom;
	while ((*clist)->before->next != (*clist)->top)
		(*clist)->before = (*clist)->before->next;
	(*clist)->top->next = (*clist)->bottom;
	free(r_node);
	r_node = NULL;
	if ((*clist)->num_of_data != 0)
		((*clist)->num_of_data)--;
	return (r_data);
}
