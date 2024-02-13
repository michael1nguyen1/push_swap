/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:46:43 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 21:57:10 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target_b(t_push_list *a, t_push_list *b)

{
	long		dif;
	t_push_list	*tmp_a;
	t_push_list	*tmp_b;

	tmp_b = b;
	tmp_a = a;
	while (b)
	{
		dif = UINT_MAX;
		while (a)
		{
			if ((b->num < a->num) && ((long)a->num - (long)b->num < dif))
			{
				dif = (long)a->num - (long)b->num;
				b->target = a;
			}
			a = a->next;
		}
		a = tmp_a;
		if (dif == UINT_MAX)
			b->target = find_min(a);
		b = b->next;
	}
	b = tmp_b;
}

void	ft_cost_b(t_push_list*b, int len_a, int len_b)
{
	t_push_list	*tmp;
	int			len_difa;
	int			len_difb;

	tmp = b;
	while (b)
	{
		len_difb = len_b - b->index;
		len_difa = len_a - b->target->index;
		set_cost_b(b, len_difa, len_difb);
		b = b->next;
	}
	b = tmp;
}

void	ft_set_node_b(t_push_list **a, t_push_list **b)
{
	int	len_b;
	int	len_a;

	len_a = ft_list_len(*a);
	len_b = ft_list_len(*b);
	ft_index(*a, len_a);
	ft_index(*b, len_b);
	ft_target_b(*a, *b);
	ft_cost_b(*b, len_a, len_b);
}
