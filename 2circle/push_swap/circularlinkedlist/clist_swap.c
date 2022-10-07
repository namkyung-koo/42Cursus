/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:18:02 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:02:13 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_linked_list.h"

void	clist_swap(t_clist **clist)
{
	t_node	*before_prev;

	before_prev = (*clist)->bottom;
	while (before_prev->next != (*clist)->before)
		before_prev = before_prev->next;
	before_prev->next = (*clist)->top;
	(*clist)->top->next = (*clist)->before;
	(*clist)->before->next = (*clist)->bottom;
	(*clist)->before = (*clist)->top;
	(*clist)->top = (*clist)->top->next;
}
