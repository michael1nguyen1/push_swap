/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:45:25 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/09 17:01:04 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}	t_push_list;

int				ft_array_len(char **array);
void			ft_free_char_array(char **array);
int				dup_check(int *array_int);
int				ft_check_alpha(char **str);
int				*ft_make_array_int(int argc, char **argv);
int				*ft_array_1(char **str);
int				*ft_array_2(char **argv);
t_push_list		*ft_make_list(int *array_int);

#endif