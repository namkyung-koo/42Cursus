/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:57:00 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/05 20:54:47 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
#include <unistd.h>

void	ft_putchar(int c)
{
	c = c + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int tab[10];
	tab[0] = 9;
	ft_foreach(tab, 1, &ft_putchar);
}
*/
