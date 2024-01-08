/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:28:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/08 14:20:13 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*array_int;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (ft_printf("Error\n"));
	array_int = ft_make_array_int(argc, argv);
	if (array_int == NULL)
		return (ft_printf("Error\n"));
	// ft_makelist();
	// sorted = ft_push_swap();
	// ft_print_list(sorted);
	return (0);
}