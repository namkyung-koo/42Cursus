/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:54:25 by nakoo             #+#    #+#             */
/*   Updated: 2022/08/29 20:37:31 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define ZEROPAD 1		/* pad with zero */
# define SIGN 2			/* unsinged/signed long */
# define PLUS 4			/* show plus */
# define SPACE 8		/* space if plus */
# define LEFT 16		/* left justified */
# define SMALL 32		/* 0x20 */
# define SPECIAL 64		/* 0x */
# define HEX 128		/* convert to hexadecimal */
# define NEGATIVE 256	/* negative number */
# define ZERO 512		/* precision zero */

typedef struct s_options
{
	int	flags;
	int	width;
	int	precision;
}	t_options;

int	ft_printf(const char *fmt, ...);
int	print_char(t_options *opt, int c);
int	print_str(t_options *opt, char *str);
int	print_decimal(t_options *opt, long long num);
int	print_hexadecimal(t_options *opt, unsigned int num);
int	print_address(t_options *opt, unsigned long long address);
int	get_length(long long num);
int	get_address_length(unsigned long long num);
int	put_padding(char c, int len);

#endif