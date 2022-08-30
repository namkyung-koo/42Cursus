/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:49:21 by nakoo             #+#    #+#             */
/*   Updated: 2022/08/30 19:51:45 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_options *opt, int c)
{
	int	printed;

	printed = 0;
	if (opt->width > 1 && !(opt->flags & LEFT))
		printed += put_padding(' ', opt->width - 1);
	ft_putchar_fd(c);
	printed += 1;
	if (opt->width > 1 && (opt->flags & LEFT))
		printed += put_padding(' ', opt->width - 1);
	return (printed);
}

int	print_str(t_options *opt, char *str)
{
	int	str_len;
	int	i;
	int	printed;

	str_len = ft_strlen(str);
	if (opt->precision <= 0)
		return (0);
	if (opt->precision < str_len)
		str_len = opt->precision;
	printed = 0;
	if (opt->width > str_len && !(opt->flags & LEFT))
		printed += put_padding(' ', opt->width - str_len);
	i = 0;
	printed += write(1, str, str_len);
	if (opt->width > str_len && (opt->flags & LEFT))
		printed += put_padding(' ', opt->width - str_len);
	return (printed);
}

int	print_decimal(t_options *opt, long long num)
{
	int	printed;
	int	num_len;

	printed = 0;
	num_len = get_length(num);
	if (num < 0)
		num_len += 1;
	if (opt->width > num_len)
	{
		put_padding(' ', opt->width - opt->precision - num_len);
	}
	return (printed);
}

int	print_hexadecimal(t_options *opt, unsigned int num)
{
}

int	print_address(t_options *opt, unsigned long long address)
{
}
