/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:50:13 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/28 14:32:38 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_is_recursive(long long nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > base_len - 1)
		ft_is_recursive(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (base[0] == '\0' || base_len == 1)
		return ;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	ft_is_recursive(nbr, base, base_len);
}
//#include <stdio.h>
//int	main(void)
//{
//	printf("------ ex04 ------\n");
//	printf("-bmLbpjci\n");
//	ft_putnbr_base(-2147483648, "abcdEFGhijkLNmopqrST");
//	printf("\n\n");
//	printf("*///////\n");
//	ft_putnbr_base(2147483647, "!@#$%^&*()<>,.?/");
//	printf("\n\n");
//	printf("-)()()(\n");
//	ft_putnbr_base(-42, "()");
//	printf("\n\n");
//	printf("[SHOULD NOT PRINT]\n");
//	ft_putnbr_base(133316, "");
//	printf("\n\n");
//	printf("[SHOULD NOT PRINT]\n");
//	ft_putnbr_base(15361, "aabc!");
//	printf("\n\n");
//	printf("59483\n");
//	ft_putnbr_base(59483, "0123456789");
//	printf("\n\n");
//	return (0);
//}
