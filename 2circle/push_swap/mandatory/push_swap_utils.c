/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:46:39 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:01:00 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(t_clist **clist)
{
	clist_clear(clist);
	write(2, "Error\n", 6);
	exit(0);
}

void	without_error_and_exit(t_clist **clist)
{
	clist_clear(clist);
	exit(0);
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (res * sign);
}

int	detect_duplicates(t_clist *a)
{
	t_node	*comp;

	while (a->bottom != a->top)
	{
		comp = a->bottom->next;
		while (comp != a->top->next)
		{
			if (a->bottom->data == comp->data)
				return (0);
			comp = comp->next;
		}
		a->bottom = a->bottom->next;
	}
	a->bottom = a->bottom->next;
	return (1);
}

int	check_sort(t_clist *a)
{
	t_node	*comp;
	int		max;
	int		flag;

	flag = 0;
	max = a->bottom->data;
	comp = a->bottom->next;
	while (comp != a->bottom)
	{
		if (max > comp->data)
			max = comp->data;
		else
		{
			flag = 1;
			break ;
		}
		comp = comp->next;
	}
	if (flag == 1)
		return (1);
	return (0);
}
