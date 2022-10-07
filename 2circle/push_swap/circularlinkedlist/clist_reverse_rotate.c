/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:35:22 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:02:07 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_linked_list.h"

void	clist_reverse_rotate(t_clist **clist)
{
	(*clist)->before = (*clist)->top;
	(*clist)->top = (*clist)->bottom;
	(*clist)->bottom = (*clist)->top->next;
}
