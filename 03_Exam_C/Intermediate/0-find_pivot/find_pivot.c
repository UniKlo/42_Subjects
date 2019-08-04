/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:41:28 by khou              #+#    #+#             */
/*   Updated: 2019/08/04 01:08:23 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int find_pivot(int *arr, int n)
{
	int r_sum = 0;
	int l_sum = 0;
	int i = 0;

	while (i < n)
	{
		r_sum += arr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		if ((i - 1) > -1)
		{
			l_sum += arr[i - 1];
			r_sum -= arr[i - 1] + arr[i];
		}
		if (l_sum == r_sum)
			return (i);
		i++;
	}
	return (-1);
}
/*
#include <stdio.h>
int     main()
{
    int arr[] = { 1, 100, 0, 0, 1 };
    int i = 5;

    printf("ret: %d\n", find_pivot(arr, i));
}
*/
