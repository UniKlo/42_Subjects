/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:45:09 by khou              #+#    #+#             */
/*   Updated: 2018/10/04 01:09:02 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		count_size(t_list *lst){ int size;  for (size = 0; lst; size++) lst = lst->next; return (size); }
	
int cmp(int a, int b)
{
	if (a < b) return (1);
	return (0);
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *beg;
	beg = lst;
	int size = count_size(lst);

    for(int i = 0; i < size - 1; ++i)
	{
        for (int j = 0; j < size - i - 1; ++j)
		{			
            if (!cmp(lst->data, lst->next->data)) 
			{
			   	int tmp = lst->data; 
				lst->data = lst->next->data;
				lst->next->data = tmp;
			}
			lst = lst->next;
		}
		lst = beg;
	}
	return(beg);
}
/* test rm b4 submit */
#include <stdio.h>
#include <stdlib.h>
void	asort(int *list, int size)
{
	for(int i = 0; i < size - 1; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (list[j]  > list[j+1]) { int tmp = list[j]; list[j] = list[j+1]; list[j+1] = tmp;}
}

void print_arr(int *list, int size){ for (int i = 0; i < size; ++i) printf("%d ", list[i]); printf("\n"); }

t_list *n(int data)
{
	t_list *ret = malloc(sizeof(t_list));
	ret->data = data;
	return (ret);
}

void	print_ls(t_list *lst)
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
//	printf("size is %d\n", count_size(l));
	
//	t_list a; a.data = 1; a.next = 0;
//	printf("%d \n", a.data);
//	printf("%d \n", l->data);
	/*
	int arr[] = {4, 1, 3, 2};
	print_arr(arr, 4);
	
	asort(arr, 4);
	print_arr(arr, 4);
	*/
}
