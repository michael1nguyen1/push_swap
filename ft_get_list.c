/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:30:50 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/04 13:34:40 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_list	*ft_get_list(int argc, char **argv)
{
	t_push_list	*list;
	char		**str;

	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (ft_check(str) == -1)
		{	
			free_array(str);
			return (NULL);
		}
		list = ft_make_list(str);
		free_array(str);
		return(list);
	}
	else
	{
		if (ft_check(&argv[1]) == -1)
			return (NULL);
		list = ft_make_list(&argv[1]);
		return (list);
	}
}
