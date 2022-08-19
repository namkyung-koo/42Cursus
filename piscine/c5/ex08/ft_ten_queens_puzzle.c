/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:42:32 by nakoo             #+#    #+#             */
/*   Updated: 2022/05/04 13:50:33 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_board(int *board)
{
	int		i;
	char	j;

	i = 0;
	while (i < 10)
	{
		j = board[i] + '0';
		write (1, &j, 1);
		i++;
	}
}

int	ft_is_board_valid(int *board, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == board[col])
			return (0);
		if (board[col] - board[i] == col - i)
			return (0);
		if (board[col] - board[i] == i - col)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_recursive(int *board, int col, int *cnt)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		ft_print_board(board);
		write (1, "\n", 1);
		(*cnt)++;
		return (1);
	}
	while (row < 10)
	{
		board[col] = row;
		if (ft_is_board_valid(board, col))
			ft_is_recursive(board, col + 1, cnt);
		row++;
	}
	return (*cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	cnt;
	int	col;

	cnt = 0;
	col = 0;
	while (col < 10)
	{
		board[col] = 0;
		col++;
	}
	col = 0;
	return (ft_is_recursive(board, col, &cnt));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
