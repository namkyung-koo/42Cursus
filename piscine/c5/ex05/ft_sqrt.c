/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:59:05 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/04 09:52:42 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt < 46341)
	{
		if (nb == sqrt * sqrt)
			return (sqrt);
		sqrt++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(6));
	printf("%d\n", ft_sqrt(7));
	printf("%d\n", ft_sqrt(8));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(2147483647));
}
*/
