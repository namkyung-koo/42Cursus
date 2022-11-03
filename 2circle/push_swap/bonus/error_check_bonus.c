/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:46:39 by nakoo             #+#    #+#             */
/*   Updated: 2022/11/02 11:14:18 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_and_null(int **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
}

void	error_and_exit(int *arr, int flag)
{
	free_and_null(&arr);
	if (flag == ERROR)
		write(2, "Error\n", 6);
	else if (flag == KO)
		write(1, "KO\n", 3);
	exit(0);
}

void	detect_duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->top)
	{
		j = i + 1;
		while (j <= a->top)
		{
			if (a->arr[i] == a->arr[j])
				error_and_exit(a->arr, ERROR);
			j++;
		}
		i++;
	}
}

void	check_sort_and_print(t_stack *a, t_stack *b)
{
	int	flag;
	int	comp;
	int	i;

	comp = a->arr[0];
	flag = NOT_SORTED;
	i = 1;
	while (i <= a->top)
	{
		if (comp > a->arr[i])
			comp = a->arr[i];
		else
			error_and_exit(a->arr, KO);
		i++;
	}
	if (b->top != -1)
	{
		free_and_null(&(a->arr));
		error_and_exit(b->arr, ERROR);
	}
	else
		write(1, "OK\n", 3);
}
