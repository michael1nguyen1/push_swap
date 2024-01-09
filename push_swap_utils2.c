/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:13:26 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/09 13:02:58 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_array_1(char **str)
{
	int			i;
	int			*array_int;
	long		check;

	i = 0;
	str = ft_split(str[1], ' ');
	if (str == NULL)
		return (NULL);
	if (ft_check_alpha(str) == -1)
	{
		ft_free_char_array(str);
		return (NULL);
	}
	array_int = malloc(sizeof(int) * ft_array_len(str));
	if (array_int == NULL)
		return (NULL);
	while (str[i])
	{
		check = ft_atol(str[i]);
		if (check > INT_MAX || check < INT_MIN)
		{
			free(array_int);
			return (NULL);
		}
		array_int[i] = check;
		i++;
	}
	ft_free_char_array(str);
	return (array_int);
}

int	*ft_array_2(char **argv)
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
		check = ft_atol(argv[i]);
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

