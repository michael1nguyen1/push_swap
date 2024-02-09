/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:09 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/09 16:04:02 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_list **ft_algo_a(t_push_list **a, t_push_list **b)
{
	t_push_list			*cheapest;
	int					len;
int h = 1;
	len = ft_list_len(*a);
	while (len > 3)
	{
		printf("\nthis is the %i time\n", h); 
	h++;
		printf("\nfirst node of A is: %i | first node of B: %i\n\n", (*a)->num, (*b)->num);
	ft_print_intlist(*a, *b);
		cheapest = ft_cheapest(*a);
		if(cheapest->cost == 0)
			push(a, b, 'a');
		else if(cheapest->median && cheapest->target->median)
			{
				while (cheapest != *a && cheapest->target != *b)
					rotate_c(a ,b);
				while (cheapest != *a || cheapest->target != *b)
				{
					if (cheapest != *a)
						rotate_a(a);
					if (cheapest->target != *b)
						rotate_b(b);
				}
			push(a, b, 'a');
			}
		else if(!cheapest->median && !cheapest->target->median)
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
		else
		{
			while (cheapest != *a && cheapest->target != *b)
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
			while (cheapest != *a || cheapest->target != *b)
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
			push(a, b, 'a');
		}
		ft_set_node_a(a, b);
		len--;
	}
	return(a);
}

t_push_list **ft_algo_b(t_push_list **a, t_push_list **b)
{
	t_push_list			*cheapest;
	// int h = 1;
	while (*b)
	{
	// printf("\nthis is the %i time\n", h); 
	// h++;
	// 	printf("\nfirst node of A is: %i | first node of B: %i\n\n", (*a)->num, (*b)->num);
	// ft_print_intlist(*a, *b);
		cheapest = ft_cheapest(*b);
		if(cheapest->cost == 0)
			push(b, a, 'b');
		else if(cheapest->median && cheapest->target->median)
			{
				while (cheapest != *b && cheapest->target != *a)
					rotate_c(a ,b);
				while (cheapest != *b || cheapest->target != *a)
				{
					if (cheapest != *b)
						rotate_b(b);
					if (cheapest->target != *a)
						rotate_a(a);
				}
			push(b, a, 'b');
			}
		else if(!cheapest->median && !cheapest->target->median)
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
		else
		{
			while (cheapest != *b && cheapest->target != *a)
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
			while (cheapest != *b || cheapest->target != *a)
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
			push(b, a, 'b');
		}
		if (*b)
			ft_set_node_b(a, b);
	}
	return(a);
}

t_push_list	*ft_cheapest(t_push_list *a)
{
	t_push_list *tmp;
	t_push_list *cheapest_node;
	int			cheapest;

	tmp = a;
	cheapest_node = a;
	cheapest = a->cost;
	if(cheapest == 0)
		return (a);
	while (a)
	{
		if(a->cost < cheapest)
		{	
			cheapest = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	a = tmp;
	return(cheapest_node);
}

void	ft_cost_a(t_push_list *a, t_push_list*b, int len_a, int len_b)
{
	t_push_list	*tmp;
	int		len_difa;
	int		len_difb;
	
	tmp = a;
	
	while (a)
	{
		len_difa = len_a - a->index;
		len_difb = len_b - a->target->index;
		if(a->median && a->target->median)
		{
			if(a->index < a->target->index)
				a->cost = a->target->index;
			else
				a->cost = a->index;
		}
		else if((!a->median) && (!a->target->median))
		{
			if(len_difa > len_difb)
				a->cost = len_difa;
			else
				a->cost = len_difb;
		}
		else
		{
			if(a->median && !a->target->median)
				a->cost = a->index + (len_b - a->target->index);
			else
				a->cost = b->index + (len_a - a->index);
		}
		a = a->next;
	}
	a = tmp;
}
void	ft_cost_b(t_push_list *a, t_push_list*b, int len_a, int len_b)
{
	t_push_list	*tmp;
	int		len_difa;
	int		len_difb;
	
	tmp = b;
	
	while (b)
	{
		len_difb = len_b - b->index;
		len_difa = len_a - b->target->index;
		if(b->median && b->target->median)
		{
			if(b->index < b->target->index)
				b->cost = b->target->index;
			else
				b->cost = b->index;
		}
		else if((!b->median) && (!b->target->median))
		{
			if(len_difb > len_difa)
				b->cost = len_difb;
			else
				b->cost = len_difa;
		}
		else
		{
			if(b->median && !b->target->median)
				b->cost = b->index + (len_a - b->target->index);
			else
				b->cost = a->index + (len_b - b->index);
		}
		b = b->next;
	}
	b = tmp;
}

void	ft_index(t_push_list *list, int len)
{
	int			i;
	int			median;
	t_push_list	*tmp;
	
	i = 0;
	tmp = list;
	if (len % 2 == 0)
		median = len/2;
	else
		median = len/2 + 1;
	while(list != NULL)
	{
		list->index = i;
		if(i < median)
			list->median = true;
		else
			list->median = false;
		list = list->next;
		i++;
	}
	list = tmp;
}
t_push_list **ft_min_to_top(t_push_list **a)
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
		while(a)
		{
			if ((b->num < a->num) && ((long)a->num < dif + b->num))
			{
				dif = a->num - b->num;
				b->target = a;
			}
			a = a->next;
		}
		a = tmp_a;
		if(dif == UINT_MAX)
			b->target = find_min(a);
		b = b->next;
	}
	b = tmp_b;
}

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
		while(b)
		{
			if ((b->num < a->num) && (a->num - b->num < dif))
			{
				dif = a->num - b->num;
				a->target = b;
			}
			b = b->next;
		}
		b = tmp_b;
		if(dif == UINT_MAX)
			a->target = find_max(b);
		a = a->next;
	}
	a = tmp;
}

void	ft_set_node_a(t_push_list **a, t_push_list **b)
{
	int len_b;
	int len_a;

	len_a = ft_list_len(*a);
	len_b = ft_list_len(*b);
	ft_index(*a, len_a);
	ft_index(*b, len_b);
	ft_target_a(*a, *b);
	ft_cost_a(*a, *b, len_a, len_b);
}

void	ft_set_node_b(t_push_list **a, t_push_list **b)
{
	int len_b;
	int len_a;

	len_a = ft_list_len(*a);
	len_b = ft_list_len(*b);
	ft_index(*a, len_a);
	ft_index(*b, len_b);
	ft_target_b(*a, *b);
	ft_cost_b(*a, *b, len_a, len_b);
}

void	ft_big_sort(t_push_list **a, t_push_list **b, int len_a)
{
	if (len_a == 4)
	{	
		push(a, b, 'a');
		ft_sort_three(a);
		return ;
	}
	else
		push(a, b, 'a');
		push(a, b, 'a');
		if (len_a - 2 == 3)
		{	
			ft_sort_three(a);
			return;
		}
	ft_set_node_a(a, b);
	ft_algo_a(a, b);
	if(!ft_check_sorted(*a))
		ft_sort_three(a);
	ft_set_node_b(a,b);
	// printf(" \nBefore Algo_b first node of A is: %i\n\n", (*a)->num);
	ft_algo_b(a, b);
	ft_min_to_top(a);
	// ft_print_intlist(*a, *b);
	// if(!ft_check_sorted(*a))
	// 	{ft_printf("FAILED");
	// 	return ;
	// 	}
	// else
	// 	ft_printf("PASSED");
	// return ;
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

void ft_sort(t_push_list **a, t_push_list **b)
{
	int list_len;

	if(!ft_check_sorted(*a))
	{
		list_len = ft_list_len(*a);
		if (list_len == 2)
			swap_a(a);
		else if(list_len == 3)
			ft_sort_three(a);
		else
			ft_big_sort(a, b, list_len);
	}
}
