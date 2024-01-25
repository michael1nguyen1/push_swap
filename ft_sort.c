/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:09 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/25 21:08:10 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort(t_push_list **list_a, t_push_list **list_b)
{
	int list_len;
	t_push_list check;

	if(!ft_check_sorted(*list_a))
	{
		list_len = ft_list_len(*list_a);
		if (list_len == 2 || list_len == 3)
			ft_sort_two_three(list_a, list_len);
		else if (list_len == 4 || list_len == 5)
			ft_sort_four_five(list_a, list_b, list_len);
		else
			ft_big_sort(list_a, list_b);
	}
}