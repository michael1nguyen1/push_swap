/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:28:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/01 16:19:28 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	static t_list	*list_a = NULL;
	static t_list	*list_b = NULL;
	t_list			*sorted;

	if (ft_errors(argc, argv) == -1)
		return (ft_printf("Error\n"));
	ft_makelist();
	sorted = ft_push_swap();
	ft_print_list(sorted);
}
