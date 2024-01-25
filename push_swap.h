/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:45:25 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/25 20:27:04 by linhnguy         ###   ########.fr       */
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
int				dup_check(char **array_int);
int				ft_check_alpha(char **str);
t_push_list		*ft_get_list(int argc, char **argv);
int				ft_check(char **str, int check);
long			ft_int_to_list(char *str);
t_push_list		*ft_make_list(char **array_int);

void			swap(t_push_list **list);
void			push(t_push_list **list_a, t_push_list **list_b);
void			rotate(t_push_list **list);
void			reverse_rotate(t_push_list **list);

t_push_list		*ft_lastnode(t_push_list *list);
int				ft_check_sorted(t_push_list *list);

#endif