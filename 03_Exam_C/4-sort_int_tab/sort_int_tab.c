/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 23:18:13 by khou              #+#    #+#             */
/*   Updated: 2018/11/25 18:09:10 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j;
	int tmp = 0;
	if (size == 0)
		return ;
	while (i < size)
	{
		j = 0;
		while(j + 1 < size)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}

    i =	0;
    while (i < size - 1)
        printf("%d ", tab[i++]);
    printf("\n");
	return ;
}

#include <stdio.h>

int		main()
{
	int tbl[5] = {7, 6, 5, 4, 1};
	int	i = 0;
	int size = 5;
	while (i < size)
		printf("%d ", tbl[i++]);
	printf("\n");
	sort_int_tab(tbl, 6);
}
