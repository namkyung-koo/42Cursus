/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:02:24 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/11 15:15:47 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_linked_list.h"

void	clist_clear(t_clist **clist)
{
	t_node	*tmp;

	while ((*clist)->num_of_data != 0)
	{
		tmp = (*clist)->bottom;
		tmp->data = 0;
		(*clist)->bottom = (*clist)->bottom->next;
		free(tmp);
		tmp = NULL;
		((*clist)->num_of_data)--;
	}
	clist_init(clist);
	if (*clist != NULL)
		free(*clist);
	(*clist) = NULL;
}
