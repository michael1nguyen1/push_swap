/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:13:26 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/25 21:15:09 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char **str, int check)
{
	if (str == NULL)
		return (-1);
	if (dup_check(str) == -1)
	{
		if (check == 1)
			free(str);
		return (-1);
	}
	if (ft_check_alpha(str) == -1)
		return (-1);
	return (0);
}

long	ft_int_to_list(char *str)
{
	int			i;
	long		check;

	i = 0;
	check = ft_atol(str);
	if (check > INT_MAX || check < INT_MIN)
	{
		free(str);
		return (-1);
	}
	return (check);
}
int ft_check_sorted(t_push_list *list)
{
	while (list->next != NULL)
	{
		if (list->num > list->next->num)
			return (-1);
		list = list->next;
	}
	return(0);
}