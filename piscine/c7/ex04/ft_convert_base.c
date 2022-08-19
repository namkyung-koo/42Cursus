/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:02:06 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/03 19:04:03 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_base(char *base);

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_reverse_array(char *res, int flag)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	if (flag == 1)
		i = 1;
	while (res[size] != '\0')
		size++;
	while (i < size)
	{
		ft_swap(&res[i], &res[size - 1]);
		i++;
		size--;
	}
	return (res);
}

char	*ft_is_while(char *res, char *base_to, long long dec, int base_to_len)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (dec < 0)
	{
		res[0] = '-';
		dec *= -1;
		flag = 1;
		i++;
	}
	while (dec > 0)
	{
		res[i] = base_to[dec % base_to_len];
		dec /= base_to_len;
		i++;
	}
	res[i] = '\0';
	return (ft_reverse_array(res, flag));
}

int	ft_check_size(int dec, int base_to_len)
{
	if (dec < base_to_len)
		return (1);
	return (1 + ft_check_size(dec / base_to_len, base_to_len));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	dec;
	char		*res;
	int			base_to_len;

	if (ft_base(base_from) == 0 || ft_base(base_from) == 1 || \
				ft_base(base_to) == 0 || ft_base(base_to) == 1)
		return (0);
	dec = ft_atoi_base(nbr, base_from);
	if (dec == 0)
	{
		res = (char *)malloc(sizeof(char) * 2);
		res[0] = base_to[0];
		res[1] = '\0';
		return (res);
	}
	base_to_len = ft_base(base_to);
	res = (char *)malloc(sizeof(char) * \
			(ft_check_size(dec, base_to_len) + 1));
	if (!res)
		return (0);
	return (ft_is_while(res, base_to, dec, base_to_len));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("-------ex04-------\n\n");
	char *str;
	str = ft_convert_base("15858", "012345678", "0123456789ABCDEF");
	printf("2A9B : %s\n", str);	
	free(str);
	str = ft_convert_base("  \t \n -+-+-28909abc", "0123456789abcdef", \
	"0123456789ABCDEFGHIJ");
	printf("-ACDADBG : %s\n", str);
	free(str);
	str = ft_convert_base(" --zzixzoz", "ozix", "POIUYTREWQ");
	printf("TWYO : %s\n", str);
	free(str);
	char base[6] = {-19, 66, -1, -8, -20, 0};
	str = ft_convert_base("++858a112", "845a", base);
	printf("B?? : %s\n", str);
	free(str);
	str = ft_convert_base("15858", "01234aa5678", "012345679ABCDEF");
	printf("null : %s\n", str);
	free(str);
	str = ft_convert_base("15858", "01278", "0");
	printf("null : %s\n", str);
	free(str);
	str = ft_convert_base("15858", "01-278", "019ABCDEF");
	printf("null : %s\n\n", str);
	free(str);
	return (0);
}
*/
