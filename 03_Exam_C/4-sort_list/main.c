/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:03:06 by khou              #+#    #+#             */
/*   Updated: 2018/10/04 10:55:55 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int cmp(int a, int b)
{
    if (a < b) return (1);
    return (0);
}

void    asort(int *list, int size)
{
    for(int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (list[j]  > list[j+1]) { int tmp = list[j]; list[j] = list[j+1]; list[j+1] = tmp;}
}

void print_arr(int *list, int size){ for (int i = 0; i < size; ++i) printf("%d ", list[i]); printf("\n")\
; }

t_list *new(int data)
{
    t_list *ret = malloc(sizeof(t_list));
    ret->data = data;
    return (ret);
}

void    print_ls(t_list *lst)
{
    while(lst)
    {
        printf("%d ", lst->data); // lst->data == (*lst).data
        lst = lst->next;
    }
    //printf("%d ", lst->data);
    printf("\n");
}

int main(){
    t_list *l = malloc(sizeof(t_list));
    t_list *l2 = malloc(sizeof(t_list));
    t_list *l3 = malloc(sizeof(t_list));
    t_list *l4 = malloc(sizeof(t_list));

    l->data = 4; l2->data = 1; l3->data = 3; l4->data = 2;
    l->next = l2; l2->next = l3; l3->next = l4; l4->next = 0;

    print_ls(l);
    printf("\n");
    print_ls(sort_list(l, &cmp));
}
