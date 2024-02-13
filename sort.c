/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:09 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 21:02:19 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_list	**ft_algo_a(t_push_list **a, t_push_list **b)
{
	t_push_list			*cheapest;
	int					len;

	len = ft_list_len(*a);
	while (len > 3)
	{
		cheapest = ft_cheapest(*a);
		if (cheapest->cost == 0)
			push(a, b, 'a');
		else if (cheapest->median && cheapest->target->median)
			both_above_a(a, b, cheapest);
		else if (!cheapest->median && !cheapest->target->median)
			both_below_a(a, b, cheapest);
		else
			neither_at_top_a(a, b, cheapest);
		ft_set_node_a(a, b);
		len--;
	}
	return (a);
}

t_push_list	**ft_algo_b(t_push_list **a, t_push_list **b)
{
	t_push_list			*cheapest;

	while (*b)
	{
		cheapest = ft_cheapest(*b);
		if (cheapest->cost == 0)
			push(b, a, 'b');
		else if (cheapest->median && cheapest->target->median)
			both_above_b(a, b, cheapest);
		else if (!cheapest->median && !cheapest->target->median)
			both_below_a(a, b, cheapest);
		else
			neither_at_top_b(a, b, cheapest);
		if (*b)
			ft_set_node_b(a, b);
	}
	return (a);
}

void	ft_big_sort(t_push_list **a, t_push_list **b, int len_a)
{
	if (len_a == 4)
	{
		sort_4(a, b);
		return ;
	}
	else
	{
		push(a, b, 'a');
		push(a, b, 'a');
		if (len_a - 2 == 3)
		{
			check_if_3(a, b);
			return ;
		}
	}
	ft_set_node_a(a, b);
	ft_algo_a(a, b);
	if (!ft_check_sorted(*a))
		ft_sort_three(a);
	ft_set_node_b(a, b);
	ft_algo_b(a, b);
	ft_min_to_top(a);
}

void	ft_sort_three(t_push_list **list)
{
	t_push_list	*max;
	t_push_list	*min;

	max = find_max(*list);
	min = find_min(*list);
	if (min->num == (*list)->num)
	{
		swap_a(list);
		rotate_a(list);
	}
	else if (min->num == (*list)->next->num && max->num
		== (*list)->next->next->num)
		swap_a(list);
	else if (max->num == (*list)->next->num && min->num
		== (*list)->next->next->num)
		reverse_rotate_a(list);
	else if ((*list)->num == max->num && min->num == (*list)->next->next->num)
	{
		rotate_a(list);
		swap_a(list);
	}
	else if ((*list)->num == max->num && min->num == (*list)->next->num)
		rotate_a(list);
}

void	ft_sort(t_push_list **a, t_push_list **b)
{
	int	list_len;

	if (!ft_check_sorted(*a))
	{
		list_len = ft_list_len(*a);
		if (list_len == 2)
			swap_a(a);
		else if (list_len == 3)
			ft_sort_three(a);
		else
			ft_big_sort(a, b, list_len);
	}
}
