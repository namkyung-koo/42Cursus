/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:02:28 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/02 10:22:37 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || \
			(base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		i++;
	}
	while (base[len] != '\0')
		len++;
	return (len);
}

int	ft_atoi(char *str, int str_idx, char *base, int sign)
{
	int	base_len;
	int	res;
	int	j;

	base_len = ft_base(base);
	res = 0;
	if (base_len == 0)
		return (0);
	while (str[str_idx] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[str_idx] == base[j])
			{
				res = res * base_len + j;
				break ;
			}
			j++;
		}
		if (base[j] == '\0')
			return (res * sign);
		str_idx++;
	}
	return (res * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_atoi(str, i, base, sign));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("------ ex05 ------\n\n");
	char ex05_str1[] = " \n -+-++-+2147483648";
	char ex05_str2[] = "   ---+AABCDESSEZ";
	char ex05_str3[] = "   ++136667";
	char ex05_str4[] = "   -----+-+!!@@#..<";
	char ex05_str5[] = "  \n \tatoi12-+123base";
	printf("-2147483648\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, "0123456789"));
	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, ""));
	printf("-67174\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABCDES"));
	printf("-1\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABZ"));
	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "A-+"));
	printf("12347\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "3405816"));
	printf("1126397\n");
	printf("%d\n\n", ft_atoi_base(ex05_str4, "!@#$%^&*()~?><'."));
	printf("27\n");
	printf("%d\n\n", ft_atoi_base(ex05_str5, "atoi"));
	return (0);
}
*/
