/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:37:15 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/05 10:25:23 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*arr;

	i = 0;
	while (src[i] != '\0')
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*src = "HELLO";
	printf("%s\n", ft_strdup(src));
	return (0);
}
*/
