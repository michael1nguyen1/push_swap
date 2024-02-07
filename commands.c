/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:24 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/07 17:17:27 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_push_list **list)
{
    t_push_list *temp;

    temp = (*list)->next;
    (*list)->next = temp->next;
    temp->next = *list;
    (*list)->prev = temp;
    temp->prev = NULL;
    *list = temp;
    write(1, "sa\n", 3);
}

void swap_b(t_push_list **list)
{
    t_push_list *temp;

    temp = (*list)->next;
    (*list)->next = temp->next;
    temp->next = *list;
    (*list)->prev = temp;
    temp->prev = NULL;
    *list = temp;
    write(1, "sb\n", 3);
}

void swap_c(t_push_list **list_a, t_push_list **list_b)
{
    t_push_list *temp;
    t_push_list *temp2;

    temp = (*list_a)->next;
    (*list_a)->next = temp->next;
    temp->next = *list_a;
    (*list_a)->prev = temp;
    temp->prev = NULL;
    *list_a = temp;
    temp2 = (*list_b)->next;
    (*list_b)->next = temp2->next;
    temp2->next = *list_b;
    (*list_b)->prev = temp2;
    temp2->prev = NULL;
    *list_b = temp2;
    write(1, "ss\n", 3);
}

void push(t_push_list **src, t_push_list **dest, char src_list)
{
    t_push_list *temp;
    
    temp = NULL;
    if (!*dest)
    {
        *dest = *src;
        *src = (*src)->next;
        (*dest)->next = NULL;
        (*dest)->prev = NULL;
        (*src)->prev = NULL;
    }
    else
    {
        temp = *src;
        *src = (*src)->next;
        temp->next = *dest;
        (*dest)->prev = temp;
        *dest = temp;
        (*dest)->prev = NULL;
        if (*src)
            (*src)->prev = NULL;
    }
    if (src_list == 'a')
        write(1, "pb\n", 3);
    else if(src_list == 'b')
        write(1, "pa\n", 3);
}

void rotate_a(t_push_list **list)
{
    t_push_list *second;

    second = (*list)->next;
    (*list)->prev = ft_lastnode(*list);
    (*list)->prev->next = *list;
    (*list)->next = NULL;
    *list = second;
    second->prev = NULL;
    write(1, "ra\n", 3);
}

