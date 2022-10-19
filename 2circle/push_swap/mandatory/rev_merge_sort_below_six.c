/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_merge_sort_below_six.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:11:38 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/18 19:58:03 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_merge_sort_below_six(t_clist **src, t_clist **dst, int nb)
{
	t_node	*min_node;

	if (nb == 6)
	{
		min_node = find_merge_min(src, (*src)->bottom->next->next);
		if (min_node->next == (*src)->before || min_node == (*src)->before)
		{
			if (min_node->next == (*src)->before)
				rotate(src, dst, ONLY);
			rotate(src, dst, ONLY);
		}
		else if (min_node == (*src)->bottom->next->next)
		{
			reverse_rotate(src, dst, ONLY);
			min_node = (*src)->bottom->next;
		}
		else if (min_node == (*src)->bottom->next || min_node == (*src)->bottom)
		{
			if (min_node == (*src)->bottom->next)
				reverse_rotate(src, dst, ONLY);
			reverse_rotate(src, dst, ONLY);
		}
		push(src, dst);
		nb--;
	}
	rev_merge_sort_below_five(src, dst, nb);
}

void	rev_merge_sort_below_five(t_clist **src, t_clist **dst, int nb)
{
	t_node	*min_node;

	if (nb == 5)
	{
		min_node = find_merge_min(src, (*src)->bottom->next);
		if (min_node->next == (*src)->before || min_node == (*src)->before)
		{
			if (min_node->next == (*src)->before)
				rotate(src, dst, ONLY);
			rotate(src, dst, ONLY);
		}
		else if (min_node == (*src)->bottom->next || min_node == (*src)->bottom)
		{
			if (min_node == (*src)->bottom->next)
				reverse_rotate(src, dst, ONLY);
			reverse_rotate(src, dst, ONLY);
		}
		push(src, dst);
		nb--;
	}
	rev_merge_sort_below_four(src, dst, nb);
}

void	rev_merge_sort_below_four(t_clist **src, t_clist **dst, int nb)
{
	t_node	*min_node;

	if (nb == 4)
	{
		min_node = find_merge_min(src, (*src)->bottom);
		if (min_node->next == (*src)->before || min_node == (*src)->before)
		{
			if (min_node->next == (*src)->before)
				rotate(src, dst, ONLY);
			rotate(src, dst, ONLY);
		}
		else if (min_node == (*src)->bottom)
			reverse_rotate(src, dst, ONLY);
		push(src, dst);
		nb--;
	}
	rev_merge_sort_below_three(src, dst, nb);
}

void	rev_merge_sort_below_three(t_clist **src, t_clist **dst, int nb)
{
	t_node	*min_node;

	if (nb == 3)
	{
		min_node = find_merge_min(src, (*src)->bottom);
		if (min_node == (*src)->before)
			rotate(src, dst, ONLY);
		else if (min_node == (*src)->bottom)
			reverse_rotate(src, dst, ONLY);
		push(src, dst);
		nb--;
	}
	rev_merge_sort_below_two(src, dst, nb);
}

void	rev_merge_sort_below_two(t_clist **src, t_clist **dst, int nb)
{
	if (nb == 2)
	{
		if ((*src)->top->data > (*src)->before->data)
			swap(src, dst, ONLY);
		push(src, dst);
	}
	push(src, dst);
}
