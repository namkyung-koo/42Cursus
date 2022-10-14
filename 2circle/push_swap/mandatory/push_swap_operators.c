/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:43:40 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/14 18:34:43 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_clist **src, t_clist **dst)
{
	int	data;

	if ((*src)->num_of_data == EMPTY)
		return ;
	data = clist_remove(src);
	clist_insert_back(dst, data);
	ft_printf("p%c\n", (*dst)->name);
}

void	swap(t_clist **src, t_clist **dst, int flag)
{
	if (flag == ONLY)
	{
		if ((*src)->num_of_data < 2)
			return ;
		clist_swap(src);
		ft_printf("s%c\n", (*src)->name);
	}
	else
	{
		if ((*src)->num_of_data < 2 || (*dst)->num_of_data < 2)
			return ;
		clist_swap(src);
		clist_swap(dst);
		ft_printf("ss\n");
	}
}

void	rotate(t_clist **src, t_clist **dst, int flag)
{
	if (flag == ONLY)
	{
		clist_rotate(src);
		ft_printf("r%c\n", (*src)->name);
	}
	else
	{
		clist_rotate(src);
		clist_rotate(dst);
		ft_printf("rr\n");
	}
}

void	reverse_rotate(t_clist **src, t_clist **dst, int flag)
{
	if (flag == ONLY)
	{
		clist_reverse_rotate(src);
		ft_printf("rr%c\n", (*src)->name);
	}
	else
	{
		clist_reverse_rotate(src);
		clist_reverse_rotate(dst);
		ft_printf("rrr\n");
	}
}

void	do_operation(t_clist **a)
{
	t_clist	*b;

	b = (t_clist *)malloc(sizeof(t_clist));
	if (!b)
		clear_and_exit(a, NULL);
	clist_init(&b);
	b->name = 'b';
	if ((*a)->num_of_data <= 5)
		sort_below_five(a, &b);
	else
		merge_sort(a, &b);
	clist_clear(a);
	clist_clear(&b);
}
