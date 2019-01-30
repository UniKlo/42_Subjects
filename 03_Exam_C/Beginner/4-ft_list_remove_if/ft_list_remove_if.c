/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:55:38 by khou              #+#    #+#             */
/*   Updated: 2019/01/17 20:02:18 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	if (!*begin_list)
		return ;
	while (*begin_list)
	{
		if (!cmp((*begin_list)->data, *data_ref))
		{
			if ((*begin_list)->next)
			{
				tmp = *begin_list;
				*begin_list = (*begin_list)->next;
				free(tmp);
			}
			else
				free(*begin_list);
		}
		else
			begin_list =& (*begin_list)->next;
	}
	
}
