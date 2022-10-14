/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:18:30 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/14 16:13:45 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*divide(t_clist **a, t_clist **b, int depth)
{
	int	*args_of_tri;
	int	triangle;
	int	tmp;
	int	i;
	int	j;

	args_of_tri = (int *)malloc(sizeof(int) * (power(3, depth)));
	if (!args_of_tri)
		clear_and_exit(a, b);
	args_of_tri[0] = (*a)->num_of_data;
	triangle = 1;
	i = -1;
	while (++i < depth)
	{
		j = -1;
		while (++j < triangle)
		{
			tmp = args_of_tri[j];
			args_of_tri[j] = (tmp / 3);
			args_of_tri[j + triangle] = (tmp / 3) + (tmp % 3);
			args_of_tri[j + triangle * 2] = (tmp / 3);
		}
		triangle *= 3;
	}
	return (args_of_tri);
}

void	merge(t_clist **src, t_clist **dst)
{
}

void	make_triangle(t_clist **a, t_clist **b, int nb)
{
	t_clist	**src;
	t_clist	**dst;

	if ((*a)->num_of_data > (*b)->num_of_data)
	{
		src = a;
		dst = b;
	}
	else
	{
		src = b;
		dst = a;
	}
	if (nb <= 6)
	{
		merge_sort_below_six(src, dst);
		return ;
	}
	merge(src, dst);
}

void	make_reverse_triangle(t_clist **a, t_clist **b, int nb)
{
	t_clist	**src;
	t_clist	**dst;

	if ((*a)->num_of_data > (*b)->num_of_data)
	{
		src = a;
		dst = b;
	}
	else
	{
		src = b;
		dst = a;
	}
	if (nb <= 6)
	{
		rev_merge_sort_below_six(src, dst);
		return ;
	}
	merge(src, dst);
}

void	merge_sort(t_clist **a, t_clist **b)
{
	int			*args_of_tri;
	int			triangle;
	int			depth;
	int			idx;
	static int	cnt;

	depth = get_depth((*a)->num_of_data);
	while (depth >= 0)
	{
		idx = -1;
		args_of_tri = divide(a, b, depth);
		move_one_third(a, b, &cnt);
		triangle = power(3, depth);
		while (++idx < triangle)
		{
			if (get_order(idx) % 2 == 0)
				make_triangle(a, b, args_of_tri[idx]);
			else
				make_reverse_triangle(a, b, args_of_tri[idx]);
		}
		depth--;
	}
	free(args_of_tri);
	if ((*a)->num_of_data == EMPTY)
		move_b_to_a(a, b);
}
