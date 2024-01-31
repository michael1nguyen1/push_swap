/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:09 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/31 17:20:26 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_cost(t_push_list *a, t_push_list*b, int len_a, int len_b)
{
	while (a)
	{
		if(a->median && b->median)
		{
			if(a->index < a->target->index)
				a->cost = a->index;
			else
				a->cost = a->target->index;
		}
		if((!a->median) && (!b->median))
		{
			if(a->index > a->target->index)
				a->cost = len_a - a->index;
			else
				a->cost = len_b - a->target->index;
		}
		if(a->median && !a->target->median)
			a->cost = a->index + (len_b - a->target->index);
		else if (!a->median && a->target->median)
			a->cost = b->index + (len_a - a->target->index);
	}
	a = a->next;
}

void ft_target(t_push_list **a, t_push_list **b)
{
	int			dif;
	int			check;
	t_push_list	*tmp;

	tmp = *a;
	check = 0;
	dif = (*a)->num - (*b)->num;
	while(*a)
	{
		while(*b)
		{
			if (((*b)->num < (*a)->num) && ((*a)->num - (*b)->num < dif))
			{
				dif = (*a)->num - (*b)->num;
				(*a)->target = *b;
				check = 1;
			}
			*b = (*b)->next;
		}
		if(check == 0)
			(*a)->target = find_max(*b);
		*a = (*a)->next;
	}
	*a = tmp;
}

void ft_index(t_push_list **list, int len)
{
	int			i;
	int			median;
	t_push_list	*tmp;
	
	i = 0;
	median = len/2;
	tmp = *list;
	while((*list) != NULL)
	{
		(*list)->index = i;
		printf("%i", (*list)->index);
		if(i < median)
			(*list)->median = true;
		else
			(*list)->median = false;
		printf("%i", (*list)->median);
		list = (*list)->next;
		i++;
	}
	*list = tmp;
}

void ft_set_node(t_push_list **a, t_push_list **b, int len_a)
{
	int len_b;

	ft_index(a,len_a);
	ft_index(b,len_a);
	ft_target(a,b);
	len_b = ft_list_len(b);
	ft_cost(*a, *b, len_a, len_b);
}

void ft_big_sort(t_push_list **list_a, int len)
{
	static t_push_list **list_b = NULL;
	
	if (len == 4)
		push(list_a, list_b, 'a');
	else
		push(list_a, list_b, 'a');
		push(list_a, list_b, 'a');
	ft_set_node(list_a, list_b, len);
}
void ft_sort_three(t_push_list **list)
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
	else if (min->num == (*list)->next->num && max->num == (*list)->next->next->num)
		swap_a(list);
	else if(max->num == (*list)->next->num && min->num == (*list)->next->next->num)
		reverse_rotate_a(list);
	else if((*list)->num == max->num && min->num == (*list)->next->next->num)
		{	
			rotate_a(list);
			swap_a(list);
		}
	else if((*list)->num == max->num && min->num == (*list)->next->num)
		rotate_a(list);
}

void ft_sort(t_push_list **list_a)
{
	int list_len;

	if(!ft_check_sorted(*list_a))
	{
		list_len = ft_list_len(*list_a);
		if (list_len == 2)
			swap_a(list_a);
		else if(list_len == 3)
			ft_sort_three(list_a);
		else
			ft_big_sort(list_a, list_len);
	}
}
