/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:46:14 by nakoo             #+#    #+#             */
/*   Updated: 2022/10/17 19:49:38 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(t_clist **a, char *args)
{
	long long	n;

	n = ft_atoll(args);
	if (n < INT_MIN || n > INT_MAX)
		error_and_exit(a);
	return (n);
}

int	main(int argc, char **argv)
{
	int		i;
	int		n;
	t_clist	*a;

	if (argc < 3)
		return (0);
	a = (t_clist *)malloc(sizeof(t_clist));
	if (!a)
		return (0);
	clist_init(&a);
	a->name = 'a';
	i = 1;
	while (i < argc)
	{
		n = parse_args(&a, argv[i]);
		clist_insert_front(&a, n);
		i++;
	}
	if (!detect_duplicates(a))
		error_and_exit(&a);
	if (!check_sort(a))
		without_error_and_exit(&a);
	do_operation(&a);
	return (0);
}
