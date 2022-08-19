/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:21:19 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/02 10:17:37 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_res(char *res, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i < size - 1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (size == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	res = (char *)malloc(sizeof(char) * \
			(len + (ft_strlen(sep) * size - 1) + 1));
	res[0] = '\0';
	return (ft_res(res, strs, sep, size));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("-------ex03-------\n\n");
    char *ex03_arr1;
    char *ex03_arr2;
    char *ex03_arr3;
	char *ex03_arr4;
	char *ex03_str[5];
	ex03_str[0] = "hello";
	ex03_str[1] = "my";
	ex03_str[2] = "name";
	ex03_str[3] = "is";
	ex03_str[4] = "hunpark!";
	ex03_arr1 = ft_strjoin(5, ex03_str, ", ");
    ex03_arr2 = ft_strjoin(5, ex03_str, "..");
    ex03_arr3 = ft_strjoin(5, ex03_str, "^_^");
	ex03_arr4 = ft_strjoin(0, ex03_str, ";;");
	printf("%s\n", ex03_arr1);
    printf("%s\n", ex03_arr2);
    printf("%s\n", ex03_arr3);
	printf("%s\n", ex03_arr4);
    free(ex03_arr1);
    free(ex03_arr2);
    free(ex03_arr3);
	free(ex03_arr4);
	return (0);
}
*/
