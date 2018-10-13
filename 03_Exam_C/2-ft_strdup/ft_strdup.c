/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:38:17 by khou              #+#    #+#             */
/*   Updated: 2018/10/12 21:21:47 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str) {int len = 0; while (*str++) ++len; return (len); }

char    *ft_strdup(char *src)
{	
	char *beg;

    if (!src)//pointer address is NULL
        return (NULL);
	int l;
	l = ft_strlen(src) + 1;
	char *cpy;
	if (!(cpy =malloc(sizeof(char) * l)))//could not malloc
		return (NULL);
	beg = cpy;
	while (l--)
		*cpy++ = *src++; //can derefernce an empty str
	return (beg);
}


/* testing*/
#include <stdio.h>

int main()
{
	char *src = "abc";
	char *str1 = NULL;
	char *str2 = "";

    printf("src:%s str2:%s\n", src, str2);
	printf("src:%s str2:%s\n", ft_strdup(src), ft_strdup(str2));
	printf("str1:%s\n", str1);
	printf("str1:%s\n", ft_strdup(str1));
	return (0);
}

