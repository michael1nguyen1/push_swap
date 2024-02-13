/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:28:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/12 19:32:15 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_list		*list_a;
	t_push_list		*list_b;

	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (write(2, "Error\n", 6));
	list_a = ft_get_list(argc, argv);
	if (!list_a)
		return (write(2, "Error\n", 6));
	ft_sort(&list_a, &list_b);
	free_list(list_a);
	return (0);
}
