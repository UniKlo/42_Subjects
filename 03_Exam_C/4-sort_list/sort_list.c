/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:45:09 by khou              #+#    #+#             */
/*   Updated: 2018/10/04 10:48:17 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		count_size(t_list *lst){ int size;  for (size = 0; lst; size++) lst = lst->next; return (size); }

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
