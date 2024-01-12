/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:28:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/12 20:15:56 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_list		*list;
	// int argc = 2;
	// char *argv[] = {"wer", "wer" "NULL"};

	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (ft_printf("Error\n"));
	list = ft_get_list(argc, argv);
	if (!list)
		return (ft_printf("Error\n"));
	while (list)
	{
		ft_printf("%i\n", list->num);
		list = list->next;
	}
	// sorted = ft_push_swap();
	// ft_print_list(sorted);
	return (0);
}
