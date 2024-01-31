/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:28:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/30 14:55:59 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_list		*list_a;
	t_push_list		*list_b;

	int len;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (ft_printf("Error\n"));
	list_a = ft_get_list(argc, argv);
	if (!list_a)
		return (ft_printf("Error\n"));
	// 	while(list_a)
	// {
	// 	printf("%i\n", list_a->num);
	// 	list_a = list_a->next;
	// }
	// ft_sort(&list_a);
	// ft_print_list(sorted);
	return (0);
}
