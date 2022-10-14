/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:45:17 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/14 18:19:48 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "c_linked_list.h"
# include "ft_printf.h"
# include <limits.h>

# define EMPTY 0
# define ONLY 1
# define BOTH 2

/* push_swap.c -- (file including main function) */
int			parse_args(t_clist **a, char *args);

/* push_swap_utils.c -- (file including functions to check error) */
int			check_sort(t_clist *a);
int			detect_duplicates(t_clist *a);
void		error_and_exit(t_clist **clist);
void		without_error_and_exit(t_clist **clist);
long long	ft_atoll(const char *str);

/* push_swap_utils2.c -- (file including funcs to need to sort args below 5) */
void		clear_and_exit(t_clist **a, t_clist **b);
void		sort_below_five(t_clist **a, t_clist **b);
void		sort_below_three(t_clist **a, t_clist **b);
t_node		*find_min(t_clist **a);
t_node		*find_max(t_clist **a);

/* push_swap_operators.c -- (file including functions to need to sort stack) */
void		do_operation(t_clist **a);
void		push(t_clist **src, t_clist **dst);
void		swap(t_clist **a, t_clist **b, int flag);
void		rotate(t_clist **a, t_clist **b, int flag);
void		reverse_rotate(t_clist **a, t_clist **b, int flag);

/* merge_sort.c -- (file including functions to need merge sort) */
int			*divide(t_clist **a, t_clist **b, int depth);
void		merge(t_clist **src, t_clist **dst);
void		merge_sort(t_clist **a, t_clist **b);
void		make_triangle(t_clist **a, t_clist **b, int nb);
void		make_reverse_triangle(t_clist **a, t_clist **b, int nb);

/* merge_sort_utils.c -- (file including additional funcs to need merge sort) */
int			get_depth(int nb);
int			get_order(int idx);
int			power(int base, int exp);
void		move_b_to_a(t_clist **a, t_clist **b);
void		move_one_third(t_clist **a, t_clist **b, int *cnt);

/* merge_sort_below_six.c -- (flie including funcs to need to merge below 6) */
void		merge_sort_below_six(t_clist **src, t_clist **dst);
void		merge_sort_below_five(t_clist **src, t_clist **dst);
void		merge_sort_below_four(t_clist **src, t_clist **dst);
void		merge_sort_below_three(t_clist **src, t_clist **dst);
void		merge_sort_below_two(t_clist **src, t_clist **dst);

/* rev_merge_sort_below_six.c-(flie including funs to need to r_merge below 6)*/
void		rev_merge_sort_below_six(t_clist **src, t_clist **dst);
void		rev_merge_sort_below_five(t_clist **src, t_clist **dst);
void		rev_merge_sort_below_four(t_clist **src, t_clist **dst);
void		rev_merge_sort_below_three(t_clist **src, t_clist **dst);
void		rev_merge_sort_below_two(t_clist **src, t_clist **dst);

#endif