/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:53:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 21:57:47 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_push_list *list, int len)
{
	int			i;
	int			median;
	t_push_list	*tmp;

	i = 0;
	tmp = list;
	if (len % 2 == 0)
		median = len / 2;
	else
		median = len / 2 + 1;
	while (list != NULL)
	{
		list->index = i;
		if (i < median)
			list->median = true;
		else
			list->median = false;
		list = list->next;
		i++;
	}
	list = tmp;
}

t_push_list	*ft_cheapest(t_push_list *a)
{
	t_push_list	*tmp;
	t_push_list	*cheapest_node;
	int			cheapest;

	tmp = a;
	cheapest_node = a;
	cheapest = a->cost;
	if (cheapest == 0)
		return (a);
	while (a)
	{
		if (a->cost < cheapest)
		{
			cheapest = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	a = tmp;
	return (cheapest_node);
}

void	set_cost_b(t_push_list *b, int len_difa, int len_difb)
{
	if (b->median && b->target->median)
	{
		if (b->index < b->target->index)
			b->cost = b->target->index;
		else
			b->cost = b->index;
	}
	else if ((!b->median) && (!b->target->median))
	{
		if (len_difb > len_difa)
			b->cost = len_difb;
		else
			b->cost = len_difa;
	}
	else
	{
		if (b->median && !b->target->median)
			b->cost = b->index + (len_difa);
		else
			b->cost = b->target->index + (len_difb);
	}
}

void	set_cost_a(t_push_list *a, int len_difa, int len_difb)
{
	if (a->median && a->target->median)
	{
		if (a->index < a->target->index)
			a->cost = a->target->index;
		else
			a->cost = a->index;
	}
	else if ((!a->median) && (!a->target->median))
	{
		if (len_difa > len_difb)
			a->cost = len_difa;
		else
			a->cost = len_difb;
	}
	else
	{
		if (a->median && !a->target->median)
			a->cost = a->index + len_difb;
		else
			a->cost = a->target->index + len_difa;
	}
}
