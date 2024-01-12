/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:30:50 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/12 20:03:05 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_list	*ft_get_list(int argc, char **argv)
{
	int			i;
	t_push_list	*list;
	char		**str;
	int			check;

	check = 0;
	i = 0;
	if (argc == 2)
	{
		check = 1;
		str = ft_split(argv[1], ' ');
		if (str == NULL || ft_check(str, check) == -1)
			free(str);
		return (NULL);
		list = ft_make_list(str);
		free(str);
	}
	else
	{
		if (ft_check(&argv[1], check) == -1)
			return (NULL);
		list = ft_make_list(&argv[1]);
		return (list);
	}
}
