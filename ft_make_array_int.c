/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:30:50 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/07 21:12:24 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_make_array_int(int argc, char **argv)
{
	int		i;
	long	check;
	int		*array_int;
	
	i = 0;
	if (argc == 2)
		array_int = ft_array_1(argv);
		if (array_int == NULL)
			return (NULL);
		if (dup_check(array_int) == -1)
	{
		free(array_int);	
		return (NULL);
	}
	else
		array_int = ft_array_2(argv);
		if (array_int == NULL)
			return (NULL);
		if (dup_check(array_int) == -1)
	{
		free(array_int);	
		return (NULL);
	}
	return (array_int);
}
