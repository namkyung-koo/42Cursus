/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:10:49 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/26 10:38:31 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[(unsigned char)str[i] / 16]);
			ft_putchar("0123456789abcdef"[(unsigned char)str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

/*
int	main(void)
{
	char	str[10] = "HELLO";
	str[1] = 0x8b;

	ft_putstr_non_printable(str);
	return (0);
}
*/
