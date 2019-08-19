/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:55:26 by exam              #+#    #+#             */
/*   Updated: 2019/08/18 18:08:35 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	biggest(int a, int b, int c)
{
	int max = 0;

	if (a > b)
		max = a;
	else 
		max = b;

	if (max > c)
		return (max);
	return (c);
}

int	gold_gain(int **mine, int n)
{
	int **gain = malloc(sizeof(int *) * n);
	int i = 0;
	int j = 0;
	while (i < n)
	{
		gain[i] = malloc(sizeof(int) * n);
		j = 0;
		while (j < n)
		{
			gain[i][j] = mine[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	int ret = 0;
	while (j < n)
    {
        i = 0;
        while (i < n)
        {
			int t = 0;
			int m = 0;
			int b = 0;
			if (i - 1 >= 0 && j - 1 >= 0)
				t = gain[i - 1][j - 1];
			if (j - 1 >= 0)
				m = gain[i][j-1];
			if (i + 1 < n && j - 1 >= 0)
				b = gain[i + 1][j - 1];
            gain[i][j] = mine[i][j] + biggest(t, m ,b);
			if (gain[i][j] > ret)
				ret = gain[i][j];
            i++;
        }
        j++;
    }
	return (ret);
}

/*
#include <stdio.h>

void	print_map(int **tab, int n)
{
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main()
{
	int n = 3;
	int **tab = malloc(sizeof(int *) * n);

	int i = 0;
	while (i < n)
	{
		tab[i] = malloc(sizeof(int) * n);
		i++;
	}
	
	tab[0][0] = 1;
	tab[0][1] = 3;
	tab[0][2] = 1;
	tab[0][3] = 5;

	tab[1][0] = 2;
    tab[1][1] = 2;
    tab[1][2] = 4;
    tab[1][3] = 1;

	tab[2][0] = 5;
    tab[2][1] = 0;
    tab[2][2] = 2;
    tab[2][3] = 3;

	tab[3][0] = 0;
    tab[3][1] = 6;
    tab[3][2] = 1;
    tab[3][3] = 2;
	

	tab[0][0] = 1;
    tab[0][1] = 2;
    tab[0][2] = 3;

    tab[1][0] = 3;
    tab[1][1] = 4;
    tab[1][2] = 8;

    tab[2][0] = 9;
    tab[2][1] = 6;
    tab[2][2] = 7;
	print_map(tab, n);

	printf("gold_gain: %d\n", gold_gain(tab, n));
}
*/
