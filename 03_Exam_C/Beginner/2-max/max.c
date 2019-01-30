
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:10:11 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 20:34:40 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int max;
	unsigned int i = 0;
	if (len == 0)
		return(0);
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/*
#include <stdio.h>
int main ()
{
	int nbr[4] = {3, 1, 2, -4};
	int i = 0;
	while (i < 4)
		printf("%d ", nbr[i++]);
	printf("\nmax: %d\n", max(nbr, 4));

	int nbr1[] = {};
	printf("\nmax: %d\n", max(nbr1, 0));
	return (0);
}
*/
