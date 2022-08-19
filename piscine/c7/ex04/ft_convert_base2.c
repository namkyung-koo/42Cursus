/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:03:08 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/03 10:25:00 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base(char *base)
{
	int	i;
	int	j;

	i = 0;
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
	return (i);
}

int	ft_atoi(char *str, int str_idx, char *base, int sign)
{
	int	base_len;
	int	res;
	int	j;

	base_len = ft_base(base);
	res = 0;
	if (base_len == 0 || base_len == 1)
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
