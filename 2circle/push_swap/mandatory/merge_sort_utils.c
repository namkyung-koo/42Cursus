/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:29:16 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/14 18:30:34 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	move_one_third(t_clist **a, t_clist **b, int *cnt)
{
	t_clist	*src;
	t_clist	*dst;
	int		nb;
	int		i;

	if (cnt % 2 == 0)
	{
		src = (*a);
		dst = (*b);
	}
	else
	{
		src = (*b);
		dst = (*a);
	}
	nb = (src->num_of_data) / 3;
	i = 0;
	while (i < nb)
	{
		push(src, dst);
		i++;
	}
	(*cnt)++;
}

void	move_b_to_a(t_clist **a, t_clist **b)
{
	while ((*b)->num_of_data != EMPTY)
	{
		reverse_rotate(b, a, ONLY);
		push(b, a);
	}
}
