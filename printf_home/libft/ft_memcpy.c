/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:24 by nakoo             #+#    #+#             */
/*   Updated: 2022/07/18 16:42:45 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (!dst && !src)
		return (0);
	tmp = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(tmp + i) = *((const unsigned char *)src + i);
		i++;
	}
	return (dst);
}
