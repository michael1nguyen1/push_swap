/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:28:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/04 13:37:46 by linhnguy         ###   ########.fr       */
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
		return (write(2, "Error\n", 6));
	list_a = ft_get_list(argc, argv);
	if (!list_a)
		return (write(2, "Error\n", 6));
	ft_sort(&list_a, &list_b);
	// while(list_a)
	// {
	// 	printf("%i\n", list_a->num);
	// 	list_a = list_a->next;
	// }
	// while(list_b)
	// {
	// 	printf("%i\n", list_b->num);
	// 	list_b = list_a->next;
	// }
	return (0);
}
