/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:33:28 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 20:25:24 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_above_a(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	while (cheapest != *a && cheapest->target != *b)
		rotate_c(a, b);
	while (cheapest != *a || cheapest->target != *b)
	{
		if (cheapest != *a)
			rotate_a(a);
		if (cheapest->target != *b)
			rotate_b(b);
	}
	push(a, b, 'a');
}

void	both_below_a(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	while (cheapest != *a && cheapest->target != *b)
		reverse_rotate_c(a, b);
	while (cheapest != *a || cheapest->target != *b)
	{
		if (cheapest != *a)
			reverse_rotate_a(a);
		if (cheapest->target != *b)
			reverse_rotate_b(b);
	}
	push(a, b, 'a');
}

static void	one_to_top(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	if (cheapest->median)
	{
		rotate_a(a);
		reverse_rotate_b(b);
	}
	else
	{
		rotate_b(b);
		reverse_rotate_a(a);
	}
}

static void	both_to_top(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	if (cheapest == *a)
	{
		if (cheapest->target->median)
			rotate_b(b);
		else
			reverse_rotate_b(b);
	}
	else
	{
		if (cheapest->median)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

void	neither_at_top_a(t_push_list **a, t_push_list **b,
t_push_list *cheapest)
{
	while (cheapest != *a && cheapest->target != *b)
		one_to_top(a, b, cheapest);
	while (cheapest != *a || cheapest->target != *b)
		both_to_top(a, b, cheapest);
	push(a, b, 'a');
}
