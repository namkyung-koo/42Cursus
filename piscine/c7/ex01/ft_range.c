/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:49:03 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/05 15:55:26 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (0);
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

#include <stdio.h>

int	main(void)
{
	printf("-------ex01-------\n\n");
    int *ex01_arr1;
    int *ex01_arr2;
    int *ex01_arr3;
    printf("min : 1, max : 10\n");
    ex01_arr1 = ft_range(1, 10);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", ex01_arr1[i]);
    }
    printf("\n\n");
    printf("min : 10, max : 1\n");
    ex01_arr2 = ft_range(1, 0);
    printf("%p ", ex01_arr2);
    printf("\n\n");
    printf("min : -25, max : -10\n");
    ex01_arr3 = ft_range(-25, -10);
    for(int i = 0; i < 15; i++)
    {
        printf("%d ", ex01_arr3[i]);
    }
    printf("\n\n");
    free(ex01_arr1);
    free(ex01_arr2);
    free(ex01_arr3);
}

