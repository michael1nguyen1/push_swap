/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:39:05 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/12 20:28:42 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	ft_free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	dup_check(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atol(array[i]) == ft_atol(array[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_alpha(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (str[i])
	{
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j++]) == 0)
				return (-1);
		}
		i++;
	}
	return (0);
}
