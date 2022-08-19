/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:03:15 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/26 19:47:04 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_berecursive(int number)
{
	int	i;
	int	j;

	i = number / 10;
	j = number % 10;
	if (i > 0)
	{
		ft_berecursive(i);
		j = j + '0';
		ft_putchar(j);
	}
	else
	{
		j = j + '0';
		ft_putchar(j);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		nb = nb * -1;
		ft_berecursive(nb);
	}
	else
		ft_berecursive(nb);
}
