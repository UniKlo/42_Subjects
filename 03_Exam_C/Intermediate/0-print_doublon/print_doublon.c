/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:02:53 by exam              #+#    #+#             */
/*   Updated: 2019/05/08 01:19:34 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int mark = 0;
	i = 0;
	j = 0;
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (mark == 1)
				printf(" ");
			printf("%d", b[j]);
			mark = 1;
			i++;
			j++;
		}
		else if (a[i] < b[j])
			i++;
		else
			j++;
	}
	printf("\n");
}

int	main()
{
	int a[11] = {-5,  4,  5,  6, 15, 50, 100, 200, 300, 1200, 5000};
	int na = 11;
	int b[8] = {2,  4,  5,  6,  7, 10,  40,  70};
	int nb = 8;

	print_doublon(a, na, b, nb); 
}

