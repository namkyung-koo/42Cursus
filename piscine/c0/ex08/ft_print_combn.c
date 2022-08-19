/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:56:29 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/28 14:20:29 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_be_recursive(int i, char cnt, char *arr, int n)
{
	if (i == n)
	{
		write(1, arr, n);
		if (arr[0] - '0' != 10 - n)
			write(1, ", ", 2);
		else
			return ;
	}
	else
	{
		while (cnt <= '9')
		{
			arr[i] = cnt;
			ft_be_recursive(i + 1, cnt + 1, arr, n);
			cnt++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	if (n < 1 || n > 9)
		return ;
	ft_be_recursive(0, '0', arr, n);
}
