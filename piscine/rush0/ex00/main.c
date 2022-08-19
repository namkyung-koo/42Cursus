/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:01:03 by eujeong           #+#    #+#             */
/*   Updated: 2022/04/17 16:13:45 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);

int	atoi(char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

int	main(int ac, char *av[])
{
	int	x;
	int	y;

	if (ac != 3)
		return (0);
	x = atoi(av[1]);
	y = atoi(av[2]);
	rush(x, y);
	return (0);
}
