/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_supplement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:42:35 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/19 13:47:52 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_clist **a, t_clist **b)
{
	while ((*b)->num_of_data != EMPTY)
	{
		reverse_rotate(b, a, ONLY);
		push(b, a);
	}
}

int	ret_one_third(int triangle, int *args_of_tri, int idx)
{
	int	one_third;
	int	i;

	one_third = 0;
	i = triangle / 3;
	while (i--)
	{
		one_third += args_of_tri[idx - 1];
		idx--;
	}
	return(one_third);
}

t_node	*find_merge_max(t_clist **src, t_node *end)
{
	t_node	*max_node;
	t_node	*comp_node;
	int		max_data;

	max_node = (*src)->bottom;
	while (max_node->next != (*src)->before)
		max_node = max_node->next;
	max_data = max_node->data;
	comp_node = max_node->next;
	while (comp_node != end->next)
	{
		if (max_node->data < comp_node->data)
		{
			max_node = comp_node;
			max_data = comp_node->data;
		}
		comp_node = comp_node->next;
	}
	return (max_node);
}

t_node	*find_merge_min(t_clist **src, t_node *end)
{
	t_node	*min_node;
	t_node	*comp_node;
	int		min_data;

	min_node = (*src)->bottom;
	while (min_node->next != (*src)->before)
		min_node = min_node->next;
	min_data = min_node->data;
	comp_node = min_node->next;
	while (comp_node != end->next)
	{
		if (min_node->data > comp_node->data)
		{
			min_node = comp_node;
			min_data = comp_node->data;
		}
		comp_node = comp_node->next;
	}
	return (min_node);
}
