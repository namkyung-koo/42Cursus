/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:45:17 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/07 20:03:00 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "c_linked_list.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

void		error_and_exit(t_clist **clist);
void		without_error_and_exit(t_clist **clist);
void		swap(t_clist **a, t_clist **b);
void		push(t_clist **src, t_clist **dst);
void		rotate(t_clist **a, t_clist **b);
void		reverse_rotate(t_clist **a, t_clist **b);
void		do_operation(t_clist **a);
void		sort_below_five(t_clist **a, t_clist **b);

int			parse_args(t_clist **a, char *args);
int			check_sort(t_clist *a);
int			detect_duplicates(t_clist *a);
int			ft_power(int base, int exp);
int			get_exponent(int n);
long long	ft_atoll(const char *str);

#endif