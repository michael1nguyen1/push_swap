/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:45:25 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/11 15:26:16 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> // remove
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				num;
	int				index;
	int 			cost;
	bool			median;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_push_list;

int				ft_array_len(char **array);
char			**free_array(char **array);
void			ft_free_char_array(char **array);
int				dup_check(char **array_int);
int				ft_check_alpha(char **str);
t_push_list		*ft_get_list(int argc, char **argv);
int				ft_check(char **str);
// t_push_list		*ft_make_list_no_split(char **array);
long			ft_int_to_list(char *str);
t_push_list		*ft_make_list(char **array_int);
void			free_list(t_push_list *list);

void 			swap_a(t_push_list **list);
void			swap_b(t_push_list **list);
void			swap_c(t_push_list **list_a, t_push_list **list_b);
void			push(t_push_list **src, t_push_list **dest, char src_list);
void			rotate_a(t_push_list **list);
void			rotate_b(t_push_list **list);
void			rotate_c(t_push_list **list_a, t_push_list **list_b);
void			reverse_rotate_a(t_push_list **list);
void			reverse_rotate_b(t_push_list **list);
void			reverse_rotate_c(t_push_list **list_a, t_push_list **list_b);

void			ft_set_node_a(t_push_list **a, t_push_list **b);
void			ft_set_node_b(t_push_list **a, t_push_list **b);
int				ft_list_len(t_push_list *list);
t_push_list		*ft_lastnode(t_push_list *list);
int				ft_check_sorted(t_push_list *list);
t_push_list		*find_max(t_push_list *list);
t_push_list		*find_min(t_push_list *list);
void			ft_sort(t_push_list **a, t_push_list **b);
void			ft_sort_three(t_push_list **list);

t_push_list		*ft_cheapest(t_push_list *a);

void ft_print_intlist(t_push_list *longlist, t_push_list *shortlist);

#endif
