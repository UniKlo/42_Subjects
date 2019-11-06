/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:31:46 by exam              #+#    #+#             */
/*   Updated: 2019/11/05 11:50:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char *ft_strdup(char *str, int beg, int l)
{
	char *ret = malloc(sizeof(char) * l);
	ret[l-1] = '\0';
	if (l == 1)
		return (ret);
	int i = 0;
	while (i < l)
	{
		ret[i] = str[beg];
		i++;
		beg++;
	}
	return (ret);
}

char    *longest_subarray(char *arr)
{
	int i = 0;
	int nbr = 0;
	int odd = 0, even = 0;
	while (arr[i])
	{
		nbr = (int)(arr[i] - '0');
		if (nbr % 2 == 0)
			odd++;
		else
			even++;
		i++;
	}
	int l_ret = odd > even ? even * 2 : odd * 2;
	while (l_ret >= 2)
	{
		int beg = 0;
		int end = strlen(arr) - 1;
		while (beg <= end - l_ret + 1)
		{
			int cp_beg = beg;
			int count = l_ret;
			int odd_ret = 0, even_ret = 0;
			while (count)
			{
				nbr = (int)(arr[cp_beg] - '0');
				if (nbr % 2 == 0)
					odd_ret++;
				else
					even_ret++;
				cp_beg++;
				count--;
			}
			if (odd_ret == even_ret)
			{
				return(ft_strdup(arr,beg,l_ret));
			}
			beg++;
		}
		l_ret--;
	}
	return (ft_strdup(arr, 0 , 1));
}
/*
#include <stdio.h>

int main()
{
	char *str = NULL;

	printf("output: %s\n", longest_subarray(str));
}
*/
