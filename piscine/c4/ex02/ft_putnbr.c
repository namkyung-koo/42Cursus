/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:10:49 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/05 16:06:58 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_recursive(int num)
{
	if (num > 9)
		ft_is_recursive(num / 10);
	ft_putchar(num % 10 + '0');
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
	}
	ft_is_recursive(nb);
}
/*
#include <stdio.h>

int	main(void)
{
printf("------ ex02 ------\n");
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(103);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(-24252);
	printf("\n\n");
	return (0);
}
*/
