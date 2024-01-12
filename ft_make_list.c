/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:41:48 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/12 21:24:19 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_list	*ft_make_list(char **array)
{
	static t_push_list	*list = NULL;
	static t_push_list	*temp = NULL;
	static int			i = (-1);
	long				check;
	t_push_list			*newnode;

	i++;
	if (!array[i])
		return (list);
	check = ft_int_to_list(array[i]);
	newnode = malloc(sizeof(t_push_list));
	if (!newnode || check == -1)
		return (NULL);
	newnode->num = check;
	newnode->next = NULL;
	newnode->prev = temp;
	if (!list)
		list = newnode;
	else
		temp->next = newnode;
	temp = newnode;
	return (ft_make_list(array));
}
