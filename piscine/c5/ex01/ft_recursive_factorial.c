/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:42:52 by nakoo             #+#    #+#             */
/*   Updated: 2022/04/27 15:45:26 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	if (nb > 1)
		res = res * ft_recursive_factorial(nb - 1);
	return (res);
}
