/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:17:13 by khou              #+#    #+#             */
/*   Updated: 2018/10/05 13:46:47 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

char *ft_strcpy(char *s1, char *s2)
{
	char *dst;

	dst = s1;
	while (*s1 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (dst);
	}



/*del b4 submit*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char dst[] = "abc";//on the stack

	char *src;//on the stack
	src = "xyz";

	char *src1 = (char *)malloc(sizeof(char) * 4);//on the heap
	src1[0] = 'B';
	src1[1] = 'I';
	src1[2] = 'T';
	src1[3] = '\0';
	
//	printf("ADDR dst: %p\tADDR s2: %p\n", dst, src);
	printf("stack dst: %s\n", dst);
	printf("stack src: %s\n", src);
	printf("stack dst: %s\n", ft_strcpy(dst, src));
	printf("heap src1: %s\n", src1);
	printf("stack dst: %s\n", ft_strcpy(dst, src1));
	return (0);
}
