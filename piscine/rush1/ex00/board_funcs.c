/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:39 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/25 21:58:49 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

// if there's already a box with the same height in the same row/col, return 0
int	is_not_duplicate(t_board *this, int i_row, int i_col, int h)
{
	if (this->in_row[i_row][h] || this->in_col[i_col][h])
		return (0);
	return (1);
}

// place and set box's height in (i_row, i_col)
// mark previous box height as absent and new box height as present
// this function does not check duplicate boxes or view count validity.
void	set_height_at(t_board *this, int i_row, int i_col, int h)
{
	int	h_prev;

	h_prev = this->height[i_row][i_col];
	this->in_row[i_row][h_prev] = 0;
	this->in_col[i_col][h_prev] = 0;
	this->in_row[i_row][h] = 1;
	this->in_col[i_col][h] = 1;
	this->height[i_row][i_col] = h;
}
