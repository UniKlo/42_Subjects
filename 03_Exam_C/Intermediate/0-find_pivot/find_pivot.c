/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:41:28 by khou              #+#    #+#             */
/*   Updated: 2019/08/04 18:22:07 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int find_pivot(int *arr, int n)
{
	int r_sum = 0;
	int l_sum = 0;
    int i = 1;

    while (i < n)
    {
        r_sum += arr[i];
        i++;
    }
    i = 1;
    while (i < n)
    {
		l_sum += arr[i - 1];
		r_sum -= arr[i];
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
