/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_linked_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:31:39 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/12 16:00:21 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_LINKED_LIST_H
# define C_LINKED_LIST_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_clist
{
	t_node	*top;
	t_node	*bottom;
	t_node	*before;
	int		num_of_data;
	char	name;
}	t_clist;

void	clist_init(t_clist **clist);
void	clist_insert_front(t_clist **clist, int data);
void	clist_insert_back(t_clist **clist, int data);
void	clist_clear(t_clist **clist);
void	clist_error(t_clist **clist);
void	clist_swap(t_clist **clist);
void	clist_rotate(t_clist **clist);
void	clist_reverse_rotate(t_clist **clist);

int		clist_remove(t_clist **clist);

#endif