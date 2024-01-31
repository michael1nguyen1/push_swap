/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:13:26 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/28 21:34:03 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_sorted(t_push_list *list)
{
	while (list->next != NULL)
	{
		if (list->num > list->next->num)
			return (0);
		list = list->next;
	}
	return(1);
}
t_push_list *find_max(t_push_list *list)
{
	t_push_list *max;

	max = list;
	while (list != NULL)
	{
		if (list->num > max->num)
			max = list;
		list = list->next;
	}
	return (max);
}
t_push_list *find_min(t_push_list *list)
{
	t_push_list *min;
	
	min = list;
	while (list != NULL)
	{
		if (list->num < min->num)
			min = list;
		list = list->next;
	}
	return (min);
}
t_push_list *ft_lastnode(t_push_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return(list);
}

int ft_list_len(t_push_list *list)
{
	int len;
	len = 0;
	while(list != NULL)
	{
		list = list->next;
		len++;
	}
	return (len);
}