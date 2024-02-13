/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:01:15 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 21:32:28 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_3(t_push_list **a, t_push_list **b)
{
	if (!ft_check_sorted(*a))
		ft_sort_three(a);
	ft_set_node_b(a, b);
	ft_algo_b(a, b);
	ft_min_to_top(a);
}

void	sort_4(t_push_list **a, t_push_list **b)
{
	push(a, b, 'a');
	if (!ft_check_sorted(*a))
		ft_sort_three(a);
	ft_set_node_b(a, b);
	ft_algo_b(a, b);
	ft_min_to_top(a);
}

t_push_list	**ft_min_to_top(t_push_list **a)
{
	t_push_list	*min;

	min = find_min(*a);
	ft_index(*a, ft_list_len(*a));
	while (min != *a)
	{
		if (min->median)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	return (a);
}

void	print_push_com(char src_list)
{
	if (src_list == 'a')
		write (1, "pb\n", 3);
	else if (src_list == 'b')
		write (1, "pa\n", 3);
}
