/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:55:43 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/04 13:14:27 by nakoo            ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	//ex07
	printf("-------ex07-------\n");
	printf("2147483647\n%d\n\n101\n%d\n\n75169\n \
	%d\n\n4894933\n%d\n\n11\n%d\n\n",\
	ft_find_next_prime(2147483640), ft_find_next_prime(100), \
   	ft_find_next_prime(75168), ft_find_next_prime(4894891),\
   	ft_find_next_prime(9));
}
*/
