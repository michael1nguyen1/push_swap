/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:03:04 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/26 16:03:19 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_b(t_push_list **list)
{
    t_push_list *second;

    second = (*list)->next;
    (*list)->prev = ft_lastnode(*list);
    (*list)->prev->next = *list;
    (*list)->next = NULL;
    *list = second;
    second->prev = NULL;
    write(1, "rb\n", 3);
}

void rotate_c(t_push_list **list_a, t_push_list **list_b)
{
    t_push_list *second;

    second = (*list_a)->next;
    (*list_a)->prev = ft_lastnode(*list_a);
    (*list_a)->prev->next = *list_a;
    (*list_a)->next = NULL;
    *list_a = second;
    second->prev = NULL;
    second = (*list_b)->next;
    (*list_b)->prev = ft_lastnode(*list_b);
    (*list_b)->prev->next = *list_b;
    (*list_b)->next = NULL;
    *list_b = second;
    second->prev = NULL;
    write(1, "rr\n", 3);
}

void reverse_rotate_a(t_push_list **list)
{
    t_push_list *last;

    last = ft_lastnode(*list);
    last->next = *list;
    last->prev->next = NULL;
    last->prev = NULL;
    (*list)->prev = last;
    *list = last;
    write(1, "rra\n", 3);
}

void reverse_rotate_b(t_push_list **list)
{
    t_push_list *last;

    last = ft_lastnode(*list);
    last->next = *list;
    last->prev->next = NULL;
    last->prev = NULL;
    (*list)->prev = last;
    *list = last;
    write(1, "rrb\n", 3);
}

void reverse_rotate_c(t_push_list **list_a, t_push_list **list_b)
{
    t_push_list *last;

    last = ft_lastnode(*list_a);
    last->next = *list_a;
    last->prev->next = NULL;
    last->prev = NULL;
    (*list_a)->prev = last;
    *list_a = last;
    last = ft_lastnode(*list_b);
    last->next = *list_b;
    last->prev->next = NULL;
    last->prev = NULL;
    (*list_b)->prev = last;
    *list_b = last;
    write(1, "rrr\n", 3);
}
