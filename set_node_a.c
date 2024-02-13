/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:44:29 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 21:57:58 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target_a(t_push_list *a, t_push_list *b)
{
	long		dif;
	t_push_list	*tmp;
	t_push_list	*tmp_b;

	tmp = a;
	tmp_b = b;
	while (a)
	{
		dif = UINT_MAX;
		while (b)
		{
			if ((b->num < a->num) && ((long)a->num - (long)b->num < dif))
			{
				dif = a->num - b->num;
				a->target = b;
			}
			b = b->next;
		}
		b = tmp_b;
		if (dif == UINT_MAX)
			a->target = find_max(b);
		a = a->next;
	}
	a = tmp;
}

void	ft_cost_a(t_push_list *a, int len_a, int len_b)
{
	t_push_list	*tmp;
	int			len_difa;
	int			len_difb;

	tmp = a;
	while (a)
	{
		len_difa = len_a - a->index;
		len_difb = len_b - a->target->index;
		set_cost_a(a, len_difa, len_difb);
		a = a->next;
	}
	a = tmp;
}

void	ft_set_node_a(t_push_list **a, t_push_list **b)
{
	int	len_b;
	int	len_a;

	len_a = ft_list_len(*a);
	len_b = ft_list_len(*b);
	ft_index(*a, len_a);
	ft_index(*b, len_b);
	ft_target_a(*a, *b);
	ft_cost_a(*a, len_a, len_b);
}
