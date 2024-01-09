/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:41:48 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/09 16:59:40 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_list	*ft_make_list(int *array_int)
{
	static t_push_list	*list = NULL;
	static t_push_list	*temp = NULL;
	static				int i = -1;
	t_push_list			*newnode;

	i++;
	if (array_int[i] && i == ft_array_len(array_int))
		return (list);
	newnode = malloc(sizeof(t_push_list));
		if (!newnode)
		return (NULL);
	newnode->num = array_int[i];
	newnode->next = NULL;
	newnode->prev = temp;
	if (!list)
		list = newnode;
	else
		list->next = newnode;
	temp = newnode;
	return (ft_make_list(array_int));	
}
