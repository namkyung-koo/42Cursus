/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:53 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/23 19:26:54 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "board.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putdigit(int d)
{
	char	c;

	c = d + '0';
	ft_putchar(c);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// print given board's height info formatted.
void	print_board(t_board *this)
{
	int	i;
	int	j;

	i = 0;
	while (i < this->size)
	{
		j = 0;
		while (j < this->size)
		{
			ft_putdigit(this->height[i][j]);
			if (j != this->size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
