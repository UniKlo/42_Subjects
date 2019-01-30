/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:50:52 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 11:46:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ls_size(t_list *ls)
{
	int size = 0;

	while (ls)
	{
		ls = ls->next;
		size++;
	}
	return (size);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *beg;
	int stime = ls_size(lst) - 1;

	beg = lst;
	while(stime)
	{
		while(lst->next)
		{
			if (!cmp(lst->data, lst->next->data))
			{
				int tmp;
				tmp = lst->next->data;
				lst->next->data = lst->data;
				lst->data = tmp;
			}
			lst = lst->next;
		}
		stime--;
		lst = beg;
	}
	return (lst);
}

/*
#include <stdio.h>

void p_ls(t_list *ls)
{
	while (ls)
	{
		printf("%d ", ls->data);
		ls = ls->next;
	}
	printf("\n");
}

int ascending(int a, int b)
{
	return (a <= b);
}

int main()
{
	t_list ls[4];

	ls[0].data = 5;
	ls[0].next = &ls[1];
	ls[1].data = 3;
	ls[1].next = &ls[2];
	ls[2].data = 1;
	ls[2].next = &ls[3];
	ls[3].data = 0;
	ls[3].next = NULL;

	p_ls(ls);
	printf("after sort\n");
	p_ls(sort_list(ls, ascending));
	return(0);
}
*/
