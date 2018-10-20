/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:30:43 by exam              #+#    #+#             */
/*   Updated: 2018/10/16 13:26:59 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include <stdio.h>

int     *ft_range(int start, int end)
{
	long long st = start;
	long long ed = end;
	long long l;
	int *ret;
	int *beg;
	
	if (ed >= st)
		l = ed - st + 1;
	else
		l = st - ed + 1;
//	printf("L: %lld\n", l);
	if (!(ret = malloc(sizeof (int)*l)))
		return (NULL);
	beg = ret;
	if (end >= start)
	{
		while (l--)
		{
			*ret = st;
//			printf("ret: %d\n", *ret);
			st++;
			ret++;
		}
	}
	else
	{
		while (l--)
		{
            *ret = st;
//			printf("ret: %d\n", *ret);
            st--;
            ret++;
		}
	}
	*ret = '\0';
	return (beg);
}

#include <stdio.h>
#include <limits.h>

int main()
{
	int *test;
	
//	test = ft_range(1, 3);
//	test = ft_range(-1, 2);
//	test = ft_range(0, 0);
	test = ft_range(, -3);
//	test = ft_range(INT_MIN, INT_MAX);
	int l = 4;
	int i = 0;
	while (i < l)
	{
		printf("test[%d]: %d\n", i,test[i]);
		i++;
	}
	printf("\n");
	return(0);
}
