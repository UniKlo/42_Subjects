/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:57:08 by khou              #+#    #+#             */
/*   Updated: 2019/03/04 21:53:43 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_pivot(int *arr, int n)
{
	int i;
	int j = 0;
	int f_sum;
	int b_sum = 0;
	
	while (j < n && j != i)
	{
		b_sum += arr[n-j-1];
		i = 0;
		f_sum = 0;
		while (i < n && f_sum < b_sum)
		{
			f_sum += arr[i];
			if (f_sum != 0 && f_sum == b_sum)
			{
				return (i + 1);
			}
			i++;
		}
		j++;
	}
	return (-1);
}

/*
#include <stdio.h>

int		main()
{
	int	arr[] = {7,8,9};
	int i = 3;
	
	printf("ret: %d\n", find_pivot(arr, i));
}
*/
