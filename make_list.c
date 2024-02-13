/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:41:48 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 20:59:12 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_push_list *list)
{
	t_push_list		*current;
	t_push_list		*next;

	if (!list)
		return ;
	while (!list)
	{
		current = list;
		next = current->next;
		free(current);
		current = next;
	}
	list = NULL;
}

static long	int_to_list(char *str)
{
	int			i;
	long		check;

	i = 0;
	check = ft_atol(str);
	if (check > INT_MAX || check < INT_MIN)
		return (LONG_MAX);
	return (check);
}

static t_push_list	*error_handle(t_push_list *list)
{
	if (!list)
		return (NULL);
	else
	{
		free_list(list);
		return (NULL);
	}
}

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
	check = int_to_list(array[i]);
	if (check == LONG_MAX)
		return (error_handle(list));
	newnode = malloc(sizeof(t_push_list));
	if (!newnode)
		return (error_handle(list));
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
