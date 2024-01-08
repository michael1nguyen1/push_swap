/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:13:26 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/07 21:13:57 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long *ft_array_1(char **str)
{
	int			i;
	int 		j;
	int			*array_int;
	
	i = 0;
	j = 0;
	str = ft_split(str[1], ' ');
	if (str == NULL)
		return (NULL);
	if (ft_check_alpha(str) == -1)
	{
		ft_free_array((void **)str);
		return (NULL);
	}
	array_int = malloc(sizeof(int) * ft_array_len(str));
	if (array_int == NULL)
		return (NULL);
	while (str[i])
	{
		array_int[i] = ft_atoi(str[i]);
		i++;
	}
	ft_free_char_array(str);
	return (array_int);
}

int *ft_array_2(char **argv)
{
	int		i;
	long	check;
	int		*array_int;

	i = 0;
	array_int = malloc(sizeof(int) * ft_array_len(argv));
	if (array_int == NULL)
		return (NULL);
	while (argv[i])
	{	
		check = ft_atoi(argv[i]);
		if (check > INT_MAX || check < INT_MIN)
		{
			free(array_int);
			return (NULL);
		}
		array_int[i] = check;
		i++;
	}
	return (array_int);
}

