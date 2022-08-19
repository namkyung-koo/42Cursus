/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:23 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/23 19:26:24 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H
# define MAX_SIZE 9

typedef struct s_board
{
	int	size;
	int	height[MAX_SIZE][MAX_SIZE];
	int	up[MAX_SIZE];
	int	down[MAX_SIZE];
	int	left[MAX_SIZE];
	int	right[MAX_SIZE];
	int	in_row[MAX_SIZE][MAX_SIZE + 1];
	int	in_col[MAX_SIZE][MAX_SIZE + 1];
}	t_board;

void	ft_putstr(char *str);
void	print_board(t_board *this);
int		solve(t_board *this, int i_grid);
t_board	*create_board(char *views);
int		is_board_valid(t_board *this, int i_last_row, int i_last_col);
int		is_not_duplicate(t_board *this, int i_row, int i_col, int h);
void	set_height_at(t_board *this, int i_row, int i_col, int h);
#endif
