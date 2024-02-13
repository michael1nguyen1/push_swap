/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:08:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 20:32:11 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_above_b(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	while (cheapest != *b && cheapest->target != *a)
		rotate_c (a, b);
	while (cheapest != *b || cheapest->target != *a)
	{
		if (cheapest != *b)
			rotate_b(b);
		if (cheapest->target != *a)
			rotate_a(a);
	}
	push(b, a, 'b');
}

void	both_below_b(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	while (cheapest != *b && cheapest->target != *a)
		reverse_rotate_c(a, b);
	while (cheapest != *b || cheapest->target != *a)
	{
		if (cheapest != *b)
			reverse_rotate_b(b);
		if (cheapest->target != *a)
			reverse_rotate_a(a);
	}
	push(b, a, 'b');
}

static void	one_to_top(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	if (cheapest->median)
	{
		rotate_b(b);
		reverse_rotate_a(a);
	}
	else
	{
		rotate_a(a);
		reverse_rotate_b(b);
	}
}

static void	both_to_top(t_push_list **a, t_push_list **b, t_push_list *cheapest)
{
	if (cheapest == *b)
	{
		if (cheapest->target->median)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	else
	{
		if (cheapest->median)
			rotate_b(b);
		else
			reverse_rotate_b(b);
	}
}

void	neither_at_top_b(t_push_list **a, t_push_list **b,
	t_push_list *cheapest)
{
	while (cheapest != *b && cheapest->target != *a)
		one_to_top(a, b, cheapest);
	while (cheapest != *b || cheapest->target != *a)
		both_to_top(a, b, cheapest);
	push(b, a, 'b');
}
