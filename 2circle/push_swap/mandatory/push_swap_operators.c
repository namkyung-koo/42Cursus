/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:43:40 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:03:51 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_clist **a, t_clist **b)
{
	if (b == NULL)
	{
		if ((*a)->num_of_data < 2)
			return ;
		clist_swap(a);
		ft_printf("sa\n");
		return ;
	}
	else if (a == NULL)
	{
		if ((*b)->num_of_data < 2)
			return ;
		clist_swap(b);
		ft_printf("sb\n");
		return ;
	}
	if ((*a)-> num_of_data < 2 || (*b)->num_of_data < 2)
		return ;
	clist_swap(a);
	clist_swap(b);
	ft_printf("ss\n");
}

void	push(t_clist **src, t_clist **dst)
{
	int	data;

	if ((*src)->num_of_data == 0)
		return ;
	data = clist_remove(src);
	clist_insert_back(dst, data);
	ft_printf("p%c\n", (*dst)->name);
}

void	rotate(t_clist **a, t_clist **b)
{
	if (b == NULL)
	{
		clist_rotate(a);
		ft_printf("ra\n");
		return ;
	}
	else if (a == NULL)
	{
		clist_rotate(b);
		ft_printf("rb\n");
		return ;
	}
	clist_rotate(a);
	clist_rotate(b);
	ft_printf("rr\n");
}

void	reverse_rotate(t_clist **a, t_clist **b)
{
	if (b == NULL)
	{
		clist_reverse_rotate(a);
		ft_printf("rra\n");
		return ;
	}
	else if (a == NULL)
	{
		clist_reverse_rotate(b);
		ft_printf("rrb\n");
		return ;
	}
	clist_reverse_rotate(a);
	clist_reverse_rotate(b);
	ft_printf("rrr\n");
}

void	do_operation(t_clist **a)
{
	t_clist	*b;

	b = (t_clist *)malloc(sizeof(t_clist));
	if (!b)
		without_error_and_exit(a);
	clist_init(&b);
	b->name = 'b';
	if ((*a)->num_of_data < 6)
		sort_below_five(a, &b);
	if ((*a)->num_of_data > 5 && get_exponent((*a)->num_of_data) % 2 == 0)
	{
		while ((*a)->num_of_data != 0)
			push(a, &b);
	}
	clist_clear(a);
	clist_clear(&b);
}
