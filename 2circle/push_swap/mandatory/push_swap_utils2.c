/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:49:07 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:48:48 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_power(int base, int exp)
{
	int	power;
	int	i;

	power = 1;
	i = 0;
	while (i < exp)
	{
		power *= base;
		i++;
	}
	return (power);
}

int	get_exponent(int n)
{
	int	exp;

	exp = 0;
	while (n != 0)
	{
		exp++;
		n /= 3;
	}
	return (exp - 1);
}

void	sort_below_five(t_clist **a, t_clist **b)
{
	t_node	*min_node;
	int		min_data;
	int		i;

	while ((*a)->num_of_data > 3)
	{
		push(a, b);
	}
	i = 0;
	min_node = (*a)->bottom;
	min_data = (*a)->bottom->data;
	while (i < 2)
	{
		i++;	
	}
	if (min_node == (*a)->top)
		rotate(a, NULL);
	else if(min_node == (a)->before)
		reverse_rotate(a, NULL);
	if ((*a)->top->data > (*a)->before->data)
		swap(a, NULL);
	reverse_rotate(a, NULL);
}
