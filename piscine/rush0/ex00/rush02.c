/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:49:42 by eujeong           #+#    #+#             */
/*   Updated: 2022/04/17 14:24:18 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw_line(int x, char left, char mid, char right)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(left);
		else if (i < x - 1)
			ft_putchar(mid);
		else
			ft_putchar(right);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (i < y && 0 < x)
	{
		if (i == 0)
			draw_line(x, 'A', 'B', 'A');
		else if (i < y - 1)
			draw_line(x, 'B', ' ', 'B');
		else
			draw_line(x, 'C', 'B', 'C');
		i++;
	}
}
