/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:16:26 by sojilee           #+#    #+#             */
/*   Updated: 2022/05/05 19:45:48 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_plus(int a, int b);
int	ft_minus(int a, int b);
int	ft_multi(int a, int b);
int	ft_div(int a, int b);
int	ft_modulo(int a, int b);

int	do_op(int a, int b, char op)
{
	int	(*ft_fp[5])(int, int);
	int	return_value;

	ft_fp[0] = ft_plus;
	ft_fp[1] = ft_minus;
	ft_fp[2] = ft_multi;
	ft_fp[3] = ft_div;
	ft_fp[4] = ft_modulo;
	if (op == '+')
		return_value = ft_fp[0](a, b);
	if (op == '-')
		return_value = ft_fp[1](a, b);
	if (op == '*')
		return_value = ft_fp[2](a, b);
	if (op == '/')
		return_value = ft_fp[3](a, b);
	if (op == '%')
		return_value = ft_fp[4](a, b);
	return (return_value);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - '0';
		str ++;
	}
	nbr *= sign;
	return (nbr);
}

void	ft_print_nbr(long long value)
{
	char	c;

	if (value < 0)
	{
		write(1, "-", 1);
		ft_print_nbr(value * (-1));
	}
	else
	{
		if (value >= 10)
			ft_print_nbr(value / 10);
		c = '0' + (value % 10);
		write(1, &c, 1);
	}
}

int	ft_is_valid(int b, char op, char *argv)
{
	if (argv[1] != 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (!(op == '+' || op == '-' || op == '*' || op == '/' || op == '%'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (op == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (op == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	op;
	int		a;
	int		b;
	int		ans;
	int		i;

	i = 0;
	if (argc > 4 || argc < 4)
		return (0);
	if (argv[2][1] != '\0')
	{
		write (1, "0\n", 2);
		return (0);
	}
	op = argv[2][0];
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (ft_is_valid(b, op, argv[2]) == 0)
		return (0);
	ans = do_op(a, b, op);
	ft_print_nbr(ans);
	write(1, "\n", 1);
	return (0);
}
