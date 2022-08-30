/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:33:55 by nakoo             #+#    #+#             */
/*   Updated: 2022/08/30 19:28:54 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_length(long long num)
{
	if (num < 0)
		num *= -1;
	if (num < 10)
		return (1);
	return (1 + get_length(num / 10));
}

int	get_address_length(unsigned long long num)
{
	if (num < 10)
		return (1);
	return (1 + get_address_length(num / 10));
}

int	put_padding(char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (len);
}

int	print_nbr(long long num, int *printed)
{
	char	c;

	if (num < 0)
		print_nbr(num * -1, printed);
	else
	{
		if (num >= 10)
			print_nbr(num / 10, printed);
		c = '0' + (num % 10);
		write(1, &c, 1);
		(*printed)++;
	}
	return (*printed);
}
