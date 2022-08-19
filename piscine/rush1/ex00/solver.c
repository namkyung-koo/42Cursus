/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:27:04 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/28 21:39:14 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

// deserialize and store grid index into (i_row, i_col)
// if index is out of bound, do nothing but return 0.
int	deserialize_index(int size, int index, int *i_row, int *i_col)
{
	if (size * size <= index)
		return (0);
	*i_row = index / size;
	*i_col = index % size;
	return (1);
}

// solve the puzzle in recursive method
// the solver will search for an empty grid.
// if there's no empty grid, consider puzzle as finished and return true.
// if there is, it will then try to fill it with value from 1 to SIZE.
// if the value is valid, it calls the function itself,
// passing the same board info, then it will wait for the return value.
// if they report that the puzzle is solved, return true.
// else, try other heights. if none of the heights are possible, return false.
int	solve(t_board *this, int i_grid)
{
	int	i_row;
	int	i_col;
	int	h;

	if (deserialize_index(this->size, i_grid, &i_row, &i_col) == 1)
	{
		h = 1;
		while (h <= this->size)
		{
			if (is_not_duplicate(this, i_row, i_col, h))
			{
				set_height_at(this, i_row, i_col, h);
				if (is_board_valid(this, i_row, i_col))
				{
					if (solve(this, i_grid + 1) == 1)
						return (1);
				}
			}
			h++;
		}
		set_height_at(this, i_row, i_col, 0);
		return (0);
	}
	return (1);
}
