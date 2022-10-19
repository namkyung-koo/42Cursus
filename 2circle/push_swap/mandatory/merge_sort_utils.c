/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:29:16 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/18 15:05:16 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_depth(int nb)
{
	int	depth;
	int	min_size;

	min_size = 5;
	depth = 0;
	while (nb > min_size)
	{
		min_size *= 3;
		depth++;
	}
	return (depth);
}

int	get_order(int idx)
{
	int	flip;
	int	range;
	int	mirror;
	int	dist;

	flip = 0;
	while (idx > 0)
	{
		range = 0;
		while (idx / power(3, range))
			range++;
		mirror = power(3, range - 1);
		dist = idx - mirror;
		dist %= mirror;
		idx = mirror - dist - 1;
		flip++;
	}
	return (flip);
}

int	power(int base, int exp)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (i < exp)
	{
		res *= base;
		i++;
	}
	return (res);
}

t_node	*set_max(t_clist **src, t_clist **dst, int *arr)
{
	t_node	*max_node;
	int		max_data;

	max_data = INT_MIN;
	if (arr[0] != EMPTY)
	{
		max_node = (*src)->top;
		max_data = (*src)->top->data;
	}
	if (arr[1] != EMPTY && max_data < (*src)->bottom->data)
	{
		max_node = (*src)->bottom;
		max_data = (*src)->bottom->data;
	}
	if (arr[2] != EMPTY && max_data < (*dst)->bottom->data)
	{
		max_node = (*dst)->bottom;
		max_data = (*dst)->bottom->data;
	}
	return (max_node);
}

t_node	*set_min(t_clist **src, t_clist **dst, int *arr)
{
	t_node	*min_node;
	int		min_data;

	min_data = INT_MAX;
	if (arr[0] != EMPTY)
	{
		min_node = (*src)->top;
		min_data = (*src)->top->data;
	}
	if (arr[1] != EMPTY && min_data < (*src)->bottom->data)
	{
		min_node = (*src)->bottom;
		min_data = (*src)->bottom->data;
	}
	if (arr[2] != EMPTY && min_data < (*dst)->bottom->data)
	{
		min_node = (*dst)->top;
		min_data = (*dst)->top->data;
	}
	return (min_node);
}
