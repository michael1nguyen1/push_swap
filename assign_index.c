/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:58:27 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/28 18:28:42 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_list(t_push_list *list)
{
	t_push_list *min;
	int			i;

	i = 1;
	while (list->next != NULL)
	{
		min = find_min(list);
		min->index = i;
		i++;
		list = list->next;
	}
}
