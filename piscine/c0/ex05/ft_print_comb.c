/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:31:56 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/16 15:39:19 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display(char i, char j, char k)
{
	if (i == '7')
	{
		write(1, "789", 3);
		return ;
	}
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				ft_display(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
