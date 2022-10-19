/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:39:34 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/18 17:54:52 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_linked_list.h"

void	clist_init(t_clist **clist)
{
	(*clist)->top = NULL;
	(*clist)->bottom = NULL;
	(*clist)->before = NULL;
	(*clist)->num_of_data = 0;
}
