/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:53:25 by nakoo             #+#    #+#             */
/*   Updated: 2022/08/30 19:12:44 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *fmt, ...);
t_options	set_options(const char **fmt);
int			get_conversion(const char **fmt, t_options *opt, va_list args);

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_options	opt;
	int			printed;

	va_start(args, fmt);
	printed = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			printed ++;
		}
		else if (*fmt == '%')
		{
			fmt++;
			opt = set_options(&fmt);
			printed += get_conversion(&fmt, &opt, args);
		}
		fmt++;
	}
	va_end(args);
	return (printed);
}

t_options	set_options(const char **fmt)
{
	t_options	opt;

	ft_memset(&opt, 0, sizeof(t_options));
	while (ft_strchr("-+# 0", **fmt))
	{
		if (**fmt == '-')
			opt.flags |= LEFT;
		else if (**fmt == '+')
			opt.flags |= PLUS;
		else if (**fmt == '#')
			opt.flags |= SPECIAL;
		else if (**fmt == ' ' && !(opt.flags & PLUS))
			opt.flags |= SPACE;
		else if (**fmt == '0' && !(opt.flags & LEFT))
			opt.flags |= ZEROPAD;
		(*fmt)++;
	}
	opt.width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt) != 0)
		(*fmt)++;
	if (**fmt == '.')
		opt.precision = ft_atoi(++(*fmt));
	while (ft_isdigit(**fmt) != 0)
		(*fmt)++;
	return (opt);
}

int	get_conversion(const char **fmt, t_options *opt, va_list args)
{
	int	printed;

	printed = 0;
	if (**fmt == 'c' || **fmt == '%')
		printed += print_char(opt, va_arg(args, int));
	else if (**fmt == 's')
		printed += print_str(opt, va_arg(args, char *));
	else if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u')
		printed += print_decimal(opt, va_arg(args, long long));
	else if (**fmt == 'x' || **fmt == 'X')
		printed += print_hexadecimal(opt, va_arg(args, unsigned int));
	else if (**fmt == 'p')
		printed += print_address(opt, va_arg(args, unsigned long long));
	return (printed);
}
