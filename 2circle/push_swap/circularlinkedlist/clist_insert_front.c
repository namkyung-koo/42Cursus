/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_insert_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:22:33 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:01:58 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_linked_list.h"

void	clist_insert_front(t_clist **clist, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		clist_error(clist);
	new_node->data = data;
	if ((*clist)->top == NULL)
	{
		(*clist)->top = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->next = (*clist)->top->next;
		(*clist)->top->next = new_node;
		if ((*clist)->num_of_data == 1)
			(*clist)->before = new_node;
	}
	(*clist)->bottom = new_node;
	((*clist)->num_of_data)++;
}
