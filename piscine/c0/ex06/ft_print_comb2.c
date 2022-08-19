/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:25:43 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/16 15:39:32 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display(char a, char b, char c, char d)
{
	if (a == '9' && b == '8')
	{
		write(1, "98 99", 5);
		return ;
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		write(1, ", ", 2);
	}
}

void	ft_divide(int i, int j)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = i / 10 + '0';
	b = i % 10 + '0';
	c = j / 10 + '0';
	d = j % 10 + '0';
	ft_display(a, b, c, d);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_divide(i, j);
			j++;
		}
		i++;
	}
}
