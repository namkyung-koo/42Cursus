/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:20:19 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:02:10 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_linked_list.h"

void	clist_rotate(t_clist **clist)
{
	(*clist)->bottom = (*clist)->top;
	(*clist)->top = (*clist)->before;
	(*clist)->before = (*clist)->bottom;
	while ((*clist)->before->next != (*clist)->top)
		(*clist)->before = (*clist)->before->next;
}
