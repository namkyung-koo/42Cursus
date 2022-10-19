/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:49:07 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/18 12:21:05 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_and_exit(t_clist **a, t_clist **b)
{
	if (a != NULL)
		clist_clear(a);
	if (b != NULL)
		clist_clear(b);
	exit(1);
}

void	sort_below_five(t_clist **a, t_clist **b)
{
	t_node	*min_node;

	while ((*a)->num_of_data > 3)
	{
		min_node = find_min(a);
		if (min_node == (*a)->bottom || min_node == (*a)->bottom->next)
		{
			if (min_node == (*a)->bottom->next)
				reverse_rotate(a, b, ONLY);
			reverse_rotate(a, b, ONLY);
		}
		else if (min_node == (*a)->bottom->next->next && (*a)->num_of_data != 4)
		{
			rotate(a, b, ONLY);
			rotate(a, b, ONLY);
		}
		else if (min_node == (*a)->before)
			rotate(a, b, ONLY);
		push(a, b);
	}
	sort_below_three(a, b);
}

void	sort_below_three(t_clist **a, t_clist **b)
{
	t_node	*min_node;

	min_node = find_min(a);
	if (min_node == (*a)->top && (*a)->before->data > (*a)->bottom->data)
	{
		reverse_rotate(a, b, ONLY);
		swap(a, b, ONLY);
	}
	else if (min_node == (*a)->before && (*a)->bottom->data > (*a)->top->data)
		swap(a, b, ONLY);
	else if (min_node == (*a)->before && (*a)->bottom->data < (*a)->top->data)
		rotate(a, b, ONLY);
	else if (min_node == (*a)->bottom && (*a)->top->data > (*a)->before->data)
	{
		swap(a, b, ONLY);
		reverse_rotate(a, b, ONLY);
	}
	else if (min_node == (*a)->bottom && (*a)->top->data < (*a)->before->data)
		reverse_rotate(a, b, ONLY);
	while ((*b)->num_of_data != 0)
		push(b, a);
}

t_node	*find_min(t_clist **a)
{
	t_node	*min_node;
	t_node	*comp_node;
	int		min_data;
	int		i;

	min_node = (*a)->bottom;
	min_data = (*a)->bottom->data;
	comp_node = (*a)->bottom->next;
	i = (*a)->num_of_data;
	while (i > 1)
	{
		if (min_node->data > comp_node->data)
		{
			min_node = comp_node;
			min_data = comp_node->data;
		}
		comp_node = comp_node->next;
		i--;
	}
	return (min_node);
}
