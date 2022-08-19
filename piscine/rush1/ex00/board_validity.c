/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:46 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 09:39:04 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

// count visible boxes in column [i_col] from "dir"
// if dir is 1, this function will check for "left" view
// and limit should be given as size of the board.
// if dir is -1, "right" view is checked and limit should be -1.
int	count_col_view_in_dir(t_board *this, int i_col, int dir, int limit)
{
	int	max_h;
	int	views;
	int	i_row;

	max_h = 0;
	views = 0;
	if (dir == 1)
		i_row = 0;
	if (dir == -1)
		i_row = this->size - 1;
	while (i_row != limit)
	{
		if (this->height[i_row][i_col] > max_h)
		{
			views++;
			max_h = this->height[i_row][i_col];
		}
		i_row += dir;
	}
	return (views);
}

// check if a column [i_col] is valid.
// the column should be full at the moment of the function call.
// if the boxes are arranged to match given view (left&right) counts, return 1.
int	is_col_valid(t_board *this, int i_col)
{
	int	views_up;
	int	views_down;

	views_up = count_col_view_in_dir(this, i_col, 1, this->size);
	views_down = count_col_view_in_dir(this, i_col, -1, -1);
	if (views_up == this->up[i_col] && views_down == this->down[i_col])
		return (1);
	return (0);
}

int	count_row_view_in_dir(t_board *this, int i_row, int dir, int limit)
{
	int	max_h;
	int	views;
	int	i_col;

	max_h = 0;
	views = 0;
	if (dir == 1)
		i_col = 0;
	if (dir == -1)
		i_col = this->size - 1;
	while (i_col != limit)
	{
		if (this->height[i_row][i_col] > max_h)
		{
			views++;
			max_h = this->height[i_row][i_col];
		}
		i_col += dir;
	}
	return (views);
}

int	is_row_valid(t_board *this, int i_row)
{
	int	views_left;
	int	views_right;

	views_left = count_row_view_in_dir(this, i_row, 1, this->size);
	views_right = count_row_view_in_dir(this, i_row, -1, -1);
	if (views_left == this->left[i_row] && views_right == this->right[i_row])
		return (1);
	return (0);
}

// returns 1 if row and col containing [i_row][i_col] are valid.
// a row is valid if:
//  1. row is not full and visible boxes from left is not more than left view.
//  2. row is full and boxes visible from left&right corresponds to given info.
// column validity is calculated in the same way with up&down views.
int	is_board_valid(t_board *this, int i_row, int i_col)
{
	int	view;

	if (i_col < this->size - 1)
	{
		view = count_row_view_in_dir(this, i_row, 1, this->size);
		if (view > this->left[i_row])
			return (0);
	}
	else
	{
		if (!is_row_valid(this, i_row))
			return (0);
	}
	if (i_row < this->size - 1)
	{
		view = count_col_view_in_dir(this, i_col, 1, this->size);
		if (view > this->up[i_col])
			return (0);
	}
	else
	{
		if (!is_col_valid(this, i_col))
			return (0);
	}
	return (1);
}
