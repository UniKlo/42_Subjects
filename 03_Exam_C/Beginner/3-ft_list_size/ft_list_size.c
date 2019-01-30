
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:39:48 by khou              #+#    #+#             */
/*   Updated: 2018/10/05 16:23:50 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	t_list head;
	t_list second;
	t_list third;

//	head.data = 1;
	head.next = &second;
	
//	second.data = 2;
	second.next = &third;
	
//	third.data = 3;
	third.next = NULL;
	printf("size of the linked list: %d\n", ft_list_size(&head));
	return (0);
}
*/
