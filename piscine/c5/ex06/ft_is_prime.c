/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:41:30 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/04 13:12:20 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	era;

	era = 2;
	if (nb < 2)
		return (0);
	while (era < 46341)
	{
		if (nb % era == 0 && nb != era)
			return (0);
		if (era > nb)
			break ;
		era++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("-------ex06-------\n");
	printf("1\n%d\n\n0\n%d\n\n0\n%d\n\n0\n%d\n\n1\n%d\n\n", \
   	ft_is_prime(2147483647), ft_is_prime(4), ft_is_prime(0), \
	ft_is_prime(4564987), ft_is_prime(149));
	printf("1\n%d\n", ft_is_prime(2));
}
*/
