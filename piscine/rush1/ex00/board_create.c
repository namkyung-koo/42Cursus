/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:33 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 21:58:58 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "board.h"

// count number of digits in (char *)str
// if str contains only ' ' (sp) or digits ('0' ~ '9') in correct order
// else, return -1
int	count_digits_if_valid(char *str)
{
	int	idx;
	int	n_numbers;

	idx = 0;
	n_numbers = 0;
	while (str[idx] != '\0')
	{
		if (idx % 2 == 0)
		{
			if ('0' <= str[idx] && str[idx] <= '9')
				n_numbers++;
			else
				return (-1);
		}
		else
		{
			if (str[idx] != ' ')
				return (-1);
		}
		idx++;
	}
	if (str[idx - 1] == ' ')
		return (-1);
	return (n_numbers);
}

// allocate and initialize struct s_board with size of (int) size
t_board	*init_board(int size)
{
	t_board	*board;
	int		i;
	int		j;

	board = (t_board *)malloc(sizeof(t_board));
	board->size = size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			board->height[i][j++] = 0;
		j = 1;
		while (j < size + 1)
		{
			board->in_row[i][j] = 0;
			board->in_col[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

// split view digits into up, down, left, right arrays
void	parse_view_str(t_board *this, char *views)
{
	int	i_str;
	int	i_digit;
	int	size;

	i_str = 0;
	i_digit = 0;
	size = this->size;
	while (views[i_str] != '\0')
	{
		if (views[i_str] != ' ')
		{
			if (i_digit / size == 0)
				this->up[i_digit % size] = views[i_str] - '0';
			if (i_digit / size == 1)
				this->down[i_digit % size] = views[i_str] - '0';
			if (i_digit / size == 2)
				this->left[i_digit % size] = views[i_str] - '0';
			if (i_digit / size == 3)
				this->right[i_digit % size] = views[i_str] - '0';
			i_digit++;
		}
		i_str++;
	}
}

// create and initialize struct board if given view str is valid
t_board	*create_board(char *views)
{
	int		n_digits;
	t_board	*board;

	n_digits = count_digits_if_valid(views);
	if (n_digits == -1 || n_digits % 4 != 0 || n_digits > MAX_SIZE * 4)
		return (NULL);
	board = init_board(n_digits / 4);
	parse_view_str(board, views);
	return (board);
}
