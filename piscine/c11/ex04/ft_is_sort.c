/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:22:40 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/05 19:39:50 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (f(tab[i], tab[i + 1]) <= 0 && i < length)
		i++;
	if (i == length)
		return (1);
	i = 0;
	while (f(tab[i], tab[i + 1]) >= 0 && i < length)
		i++;
	if (i == length)
		return (1);
	return (0);
}
