/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:24 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/25 19:09:00 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_push_list **list)
{
    t_push_list *temp;

    temp = (*list)->next;
    (*list)->next = temp->next;
    temp->next = *list;
    (*list)->prev = temp;
    temp->prev = NULL;
}

void push(t_push_list **list_a, t_push_list **list_b)
{
    t_push_list *temp;
    
    temp = NULL;
    if (!*list_b)
    {
        *list_b = *list_a;
        *list_a = (*list_a)->next;
        (*list_b)->next = NULL;
        (*list_a)->prev = NULL;
    }
    else
    {
        temp = *list_a;
        *list_a = (*list_a)->next;
        temp->next = *list_b;
        (*list_b)->prev = temp;
        *list_b = temp;
        (*list_a)->prev = NULL;
    }
}
void rotate(t_push_list **list)
{
    t_push_list *second;

    second = (*list)->next;
    (*list)->prev = ft_lastnode(*list);
    (*list)->prev->next = *list;
    (*list)->next = NULL;
    *list = second;
    second->prev = NULL;
}
void reverse_rotate(t_push_list **list)
{
    t_push_list *last;

    last = ft_lastnode(*list);
    last->next = *list;
    last->prev->next = NULL;
    last->prev = NULL;
    (*list)->prev = last;
    *list = last;
}
