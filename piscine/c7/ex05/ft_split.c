/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:33:31 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/04 18:08:50 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*str_ndup(char *src, int n)
{
	int		i;
	char	*arr;

	i = 0;
	if (n <= 0)
		return (0);
	arr = (char *)malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (0);
	while (i < n)
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**str_slice(char **split, char *str, char *charset)
{
	int		addr;
	int		now;
	int		i;

	now = 0;
	i = 0;
	while (is_charset(str[now], charset))
		now++;
	addr = now;
	while (str[now] != '\0')
	{
		if (is_charset(str[now], charset) && \
				!(is_charset(str[now + 1], charset)))
			addr = now + 1;
		else if (!(is_charset(str[now], charset)) && \
				(is_charset(str[now + 1], charset) || str[now + 1] == '\0'))
		{
			split[i] = str_ndup(&str[addr], now - addr + 1);
			i++;
		}
		now++;
	}
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		cnt;
	char	**split;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(str[i], charset) && \
			   	(is_charset(str[i + 1], charset) || str[i + 1] == '\0'))
			cnt++;
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!split)
		return (0);
	split[cnt] = 0;
	return (str_slice(split, str, charset));
}

#include <stdio.h>

int	main(void)

{
	printf("-------ex05-------\n\n");
    char **ex05_split1;
    char **ex05_split2;
    char **ex05_split3;
	char *ex05_str1 = "hello my name is hunpark!";
	char *ex05_str2 = "good@day!cat#dog!vim12!";
	char *ex05_str3 = "i1my2me3mine4you5your6you7yours";
	ex05_split1 = ft_split(ex05_str1, " ");
    ex05_split2 = ft_split(ex05_str2, "@!#");
    ex05_split3 = ft_split(ex05_str3, "1234567");
    printf("---test1---\n");
	for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ex05_split1[j]);
	}
    printf("\n\n");
    printf("---test2---\n");
    for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ex05_split2[j]);
	}
    printf("\n\n");
    printf("---test3---\n");
    for (int j = 0; j < 8; j++)
	{
		printf("%s\n", ex05_split3[j]);
	}
    printf("\n\n");
	free(ex05_split1);
    free(ex05_split3);
    free(ex05_split2);
		printf("\n----------------------ex05----------------------------\n");
		char str[1000] ="	  	     	  ";
		char sep[100] = " ";
		char **result = ft_split(str, sep);
		int	i = 0;
		while (result[i])
		{
			printf("%s::::: ", result[i]);
			i++;
		}
		//printf("%s\n", result[0]);
}

