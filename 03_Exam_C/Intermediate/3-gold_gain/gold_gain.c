/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:05:22 by exam              #+#    #+#             */
/*   Updated: 2019/07/23 12:40:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int max_ar(int a, int b, int c)
{
	int max = -1;
	if (a > max)
		max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
	return (max);
}

int gold_gain(int **mine, int n)
{
	int **tab = malloc(sizeof (int *) * n);
	int i = 0;

    while (i < n)
    {
		tab[i]= malloc(sizeof (int) * n);
        int j = 0;
        while (j < n)
        {
            tab[i][j] = 0;
            j++;
        }
        i++;
    }
	int max = -1;
	int j = 0;
    while (j < n)
    {
        i = 0;
		while (i < n)
		{
			int rt = 0;
			int r = 0;
			int rd = 0;
            if (i - 1 > -1 && j - 1 > -1)
                rt += mine[i - 1][j - 1];
			if (j - 1 > -1)
				r += mine[i][j - 1];
            if (i + 1 < n && j - 1 > -1)
                rd += mine[i + 1][j - 1];

            tab[i][j] = max_ar(rt, r, rd) + mine[i][j];
			mine[i][j] = tab[i][j];
			if (tab[i][j] > max)
				max = tab[i][j]; 
            i++;
		}
        j++;
    }
	return (max);

}

/*
int main()
{
	int n = 3;
	int **mine = malloc(sizeof (int *) * n);
	mine[0] = malloc(sizeof (int) * n);
	mine[1] = malloc(sizeof (int) * n);
	mine[2] = malloc(sizeof (int) * n);

	mine[0][0] = 1;
	mine[0][1] = 2;
	mine[0][2] = 3;

    mine[1][0] = 3;
    mine[1][1] = 4;
    mine[1][2] = 8;

    mine[2][0] = 9;
    mine[2][1] = 6;
    mine[2][2] = 7;
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			printf("%d ", mine[i][j]);
			j++;
		}
		printf("\n");
		i++;
	} 
	printf("********************\n");
	printf("gold_gain: %d\n", gold_gain(mine, n));
}
*/
