/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:22:35 by khou              #+#    #+#             */
/*   Updated: 2019/01/17 16:45:19 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(int *))
{
	while(begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*
int		main()
{
	t_list list[4];

	list[0].data = 7;
	list[1].data = 5;
	list[2].data = 3;
	list[3].data = 1;
	list[0].next = &list[1];
	list[1].next = &list[2];
	list[2].next = &list[3];
	list[3].next = NULL;

	ft_list_foreach(&list[0], &f);
	return (0);
}
*/
