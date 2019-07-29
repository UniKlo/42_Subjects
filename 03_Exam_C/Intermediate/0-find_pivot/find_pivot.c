/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:45:14 by khou              #+#    #+#             */
/*   Updated: 2019/07/28 18:59:54 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_pivot(int *arr, int n)
{
	int i = 0;
	int j = n - 1;
	int l_sum;
	int r_sum = 0;
	
	while (j && j != i)
	{
		r_sum += arr[j];
		i = 0;
		l_sum = 0;
		while (i < n && l_sum < r_sum)
		{
			l_sum += arr[i];
			if (l_sum == r_sum)
			{
				return (i + 1);
			}
			i++;
		}
		j--;
	}
	return (-1);
}

/*
#include <stdio.h>
int		main()
{
	int	arr[] = {-5, 10, 2, 5};
	int i = 4;
	
	printf("ret: %d\n", find_pivot(arr, i));
}
*/
