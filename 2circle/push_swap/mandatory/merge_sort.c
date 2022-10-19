/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:18:30 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/19 13:50:11 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		triangle = power(3, depth);
		while (++idx < triangle)
		{
			if (get_order(idx) % 2 == 0 && cnt == 0)
				merge_sort_below_six(a, b, args_of_tri[idx]);
			else if (get_order(idx) % 2 == 0)
				merge(a, b, args_of_tri[idx]);
			else if (get_order(idx) % 2 == 1 && cnt == 0)
				rev_merge_sort_below_six(a, b, args_of_tri[idx]);
			else
				reverse_merge(a, b, args_of_tri[idx]);
		}
		move_one_third(a, b, ret_one_third(triangle, args_of_tri, idx), &cnt);
		free(args_of_tri);
		depth--;
	}
	if ((*a)->num_of_data == EMPTY)
		move_b_to_a(a, b);
}

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

void	move_one_third(t_clist **a, t_clist **b, int idx, int *cnt)
{
	int		i;

	i = 0;
	if ((*cnt) % 2 == 0)
	{
		while (i < idx)
		{
			push(b, a);
			i++;
		}
	}
	else
	{
		while (i < idx)
		{
			push(a, b);
			i++;
		}
	}
	(*cnt)++;
}

void	merge(t_clist **src, t_clist **dst, int nb)
{
	int	max;
	int	arr[3];

	arr[0] = nb / 3;
	arr[1] = nb / 3 + nb % 3;
	arr[2] = nb / 3;
	while (nb > 0)
	{
		max = (set_max(src, dst, arr)->data);
		if (max == (*src)->top->data)
		{
			push(src, dst);
			arr[0]--;
		}
		else if (max == (*src)->bottom->data)
		{
			reverse_rotate(src, dst, ONLY);
			push(src, dst);
			arr[1]--;
		}
		else if (max == (*dst)->bottom->data)
		{
			reverse_rotate(dst, src, ONLY);
			arr[2]--;
		}
		nb--;
	}
}

void	reverse_merge(t_clist **src, t_clist **dst, int nb)
{
	int	min;
	int	arr[3];

	arr[0] = nb / 3;
	arr[1] = nb / 3 + nb % 3;
	arr[2] = nb / 3;
	while (nb > 0)
	{
		min = (set_min(src, dst, arr)->data);
		if (min == (*src)->top->data)
		{
			push(src, dst);
			arr[0]--;
		}
		else if (min == (*src)->bottom->data)
		{
			reverse_rotate(src, dst, ONLY);
			push(src, dst);
			arr[1]--;
		}
		else if (min == (*dst)->bottom->data)
		{
			reverse_rotate(dst, src, ONLY);
			arr[2]--;
		}
		nb--;
	}
}
