/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:07:19 by exam              #+#    #+#             */
/*   Updated: 2018/10/16 12:02:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c =='\n')
		return (1);
	return (0);
}

//#include <stdio.h>

char    **ft_split(char *str)
{
	char **ret; 
	if (!(ret = malloc(sizeof(char*) * 5000)))
		return NULL;
	int i;
	int j = 0;
//	if (!*str)
//		return NULL;
	while (*str)
	{
		while(is_space(*str) && *str)
			str++;
		i = 0;
		if (!*str)
			break;
		if (!(ret[j] = malloc(sizeof(char)*5000)))
			return (NULL);
		while(!is_space(*str) && *str)
		{
			ret[j][i] = *str;
//			printf("%c\n", ret[j][i]);
			i++;
			str++;
		}
		ret[j][i] = '\0';
//		printf("ret[%d]: %s\n", j, ret[j]);
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

/*
#include <stdio.h>
int main()
{
	char *test = "   aabbcc ddff    ";
//	char *ret[5000];
	char **ret;

	ret = ft_split(test);

//	ret = {"abc", "bcd"};
//	ret[0] = "abc";
//	ret[1] = "bcd";

//	int i = 0;
	int j = 0;

	while (ret[j])
	{
		printf("%s\n", ret[j]);
		j++;
	}
	return (0);
}
*/
