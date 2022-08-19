/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:58 by donghyle          #+#    #+#             */
/*   Updated: 2022/04/26 12:50:05 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "board.h"

int	main(int argc, char **argv)
{
	int		solution_possible;
	t_board	*board;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	board = create_board(argv[1]);
	if (board == NULL)
	{
		ft_putstr("Error\n");
		return (0);
	}
	solution_possible = solve(board, 0);
	if (solution_possible == 1)
		print_board(board);
	else
		ft_putstr("Error\n");
	free(board);
	return (0);
}
