/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:30:50 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/13 20:57:09 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_signs(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		j = 1;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check(char **str)
{
	if (dup_check(str) == -1)
		return (-1);
	if (ft_check_alpha(str) == -1)
		return (-1);
	if (check_signs(str) == -1)
		return (-1);
	return (0);
}

static t_push_list	*use_split(char **str)
{
	t_push_list	*list;

	str = ft_split(str[1], ' ');
	if (!str)
		return (NULL);
	if (ft_check(str) == -1)
	{
		free_array(str);
		return (NULL);
	}
	list = ft_make_list(str);
	if (list == NULL)
	{
		free_array(str);
		return (NULL);
	}
	free_array(str);
	return (list);
}

t_push_list	*ft_get_list(int argc, char **argv)
{
	t_push_list	*list;

	if (argc == 2)
		return (use_split(argv));
	else
	{
		if (ft_check(&argv[1]) == -1)
			return (NULL);
		list = ft_make_list(&argv[1]);
		return (list);
	}
}
