/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 23:18:13 by khou              #+#    #+#             */
/*   Updated: 2018/11/19 23:45:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int tmp = 0;
	if (size == 1)
		return ;
	tab[size-1] = '\0';
	while (size - 2)
	{
		i = 0;
		while(tab[i + 1])
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
/*
    i =	0;
    while (tab[i])
        printf("%d ", tab[i++]);
    printf("\n");
*/	
	return ;
}

#include <stdio.h>

int		main()
{
	int tbl[6] = {7, 6, 5, 4, 1};
	int	i = 0;
	while (tbl[i])
		printf("%d ", tbl[i++]);
	printf("\n");
	sort_int_tab(tbl, 6);
}
