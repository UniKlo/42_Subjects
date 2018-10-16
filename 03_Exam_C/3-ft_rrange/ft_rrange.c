/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 22:17:21 by khou              #+#    #+#             */
/*   Updated: 2018/10/14 23:47:36 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start1, int end1)
{
	int *ret;
	long long tmp;
	long long start = start1;
	long long end = end1;
	long long l = 0;

	if (start > end)
	{
		tmp = end;
		end = start;
		start = end;
	}
	printf("start: %lld\nend: %lld\n", start, end);
	
	l = end - start + 1;
	printf("l: %lld\n", l);
//	fflush(stdout);
	if (!(ret = malloc(sizeof(int) * l)))
		return (NULL);
	if (start == 0 && end == 0)
		ret[0] = 0;
	while (start < end + 1)
	{
		ret[l - 1] = end;
//		printf("ret[%lld] = %lld\n", l - 1, end);
		l--;
		end--;
	}
	printf("here\n");
	return (ret);
}

#include <stdio.h>
#include <limits.h>

int		main()
{
	int *tbl;
	tbl = ft_rrange(INT_MIN + 2, INT_MAX);

//	int tbl[3] = { 1, 2, 3};
	long long i = (long long)INT_MAX -(long long)INT_MIN + 1;
	while(i)
	{
		printf("%d ", tbl[i - 1]);
		i--;
	}
//	printf("%d ", *ft_rrange(1, 3));		
	return (0);
}
