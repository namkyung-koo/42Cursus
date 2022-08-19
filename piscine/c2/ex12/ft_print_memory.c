/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:47:59 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/20 10:15:20 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_be_recursive(unsigned long long addr)
{
	if (addr < 16)
	{
		ft_putchar("0123456789abcdef"[addr]);
		return ;
	}
	ft_be_recursive(addr / 16);
	ft_putchar("0123456789abcdef"[addr % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	address;
	int					i;

	i = 0;
	address = (unsigned long long)addr;
	if (size == 0)
		return ;
	return ((void *)ft_be_recursive(addr));
}
