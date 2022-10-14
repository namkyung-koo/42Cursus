/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_below_six.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:09:11 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/14 18:37:19 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_below_six(t_clist **src, t_clist **dst)
{
}

void	merge_sort_below_five(t_clist **src, t_clist **dst)
{
}

void	merge_sort_below_four(t_clist **src, t_clist **dst)
{
}

void	merge_sort_below_three(t_clist **src, t_clist **dst)
{
	if ((*src)->num_of_data == 3)
	{
		
	}
}

void	merge_sort_below_two(t_clist **src, t_clist **dst)
{
	if ((*src)->num_of_data == 2)
	{
		if ((*src)->top->data < (*src)->before->data)
			swap(src, dst, ONLY);
		push(src, dst);
	}
	push(src, dst);
}
