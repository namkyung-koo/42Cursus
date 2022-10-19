/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_below_six.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:09:11 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/18 19:53:33 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_below_six(t_clist **src, t_clist **dst, int nb)
{
	t_node	*max_node;

	if (nb == 6)
	{
		max_node = find_merge_max(src, (*src)->bottom->next->next);
		if (max_node->next == (*src)->before || max_node == (*src)->before)
		{
			if (max_node->next == (*src)->before)
				rotate(src, dst, ONLY);
			rotate(src, dst, ONLY);
		}
		else if (max_node == (*src)->bottom->next->next)
		{
			reverse_rotate(src, dst, ONLY);
			max_node = (*src)->bottom->next;
		}
		else if (max_node == (*src)->bottom->next || max_node == (*src)->bottom)
		{
			if (max_node == (*src)->bottom->next)
				reverse_rotate(src, dst, ONLY);
			reverse_rotate(src, dst, ONLY);
		}
		push(src, dst);
		nb--;
	}
	merge_sort_below_five(src, dst, nb);
}

void	merge_sort_below_five(t_clist **src, t_clist **dst, int nb)
{
	t_node	*max_node;

	if (nb == 5)
	{
		max_node = find_merge_max(src, (*src)->bottom->next);
		if (max_node->next == (*src)->before || max_node == (*src)->before)
		{
			if (max_node->next == (*src)->before)
				rotate(src, dst, ONLY);
			rotate(src, dst, ONLY);
		}
		else if (max_node == (*src)->bottom->next || max_node == (*src)->bottom)
		{
			if (max_node == (*src)->bottom->next)
				reverse_rotate(src, dst, ONLY);
			reverse_rotate(src, dst, ONLY);
		}
		push(src, dst);
		nb--;
	}
	merge_sort_below_four(src, dst, nb);
}

void	merge_sort_below_four(t_clist **src, t_clist **dst, int nb)
{
	t_node	*max_node;

	if (nb == 4)
	{
		max_node = find_merge_max(src, (*src)->bottom);
		if (max_node->next == (*src)->before || max_node == (*src)->before)
		{
			if (max_node->next == (*src)->before)
				rotate(src, dst, ONLY);
			rotate(src, dst, ONLY);
		}
		else if (max_node == (*src)->bottom)
			reverse_rotate(src, dst, ONLY);
		push(src, dst);
		nb--;
	}
	merge_sort_below_three(src, dst, nb);
}

void	merge_sort_below_three(t_clist **src, t_clist **dst, int nb)
{
	t_node	*max_node;

	if (nb == 3)
	{
		max_node = find_merge_max(src, (*src)->bottom);
		if (max_node == (*src)->before)
			rotate(src, dst, ONLY);
		else if (max_node == (*src)->bottom)
			reverse_rotate(src, dst, ONLY);
		push(src, dst);
		nb--;
	}
	merge_sort_below_two(src, dst, nb);
}

void	merge_sort_below_two(t_clist **src, t_clist **dst, int nb)
{
	if (nb == 2)
	{
		if ((*src)->top->data < (*src)->before->data)
			swap(src, dst, ONLY);
		push(src, dst);
	}
	push(src, dst);
}
