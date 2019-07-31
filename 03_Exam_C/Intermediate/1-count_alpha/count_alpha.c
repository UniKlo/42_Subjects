/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:15:33 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 10:52:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int count[126];
		int i = 0;
		while (i < 126)
			count[i++] = 0;
		i = 32;
		char order[126];
		i = 0;
		while (i < 126)
			order[i++] = '\0';
		while (*argv[1])
		{
			char c = *argv[1];
			if (c >= 65 && c <= 90)
				c = c + 32;
			if (c >= 97 && c <= 122)
				count[(int)c]++;
			i = 0;
			while (order[i])
			{
				if (order[i] == c)
					break;
				i++;
			}
			if (!order[i] && (c >= 97&& c <=122))
				order[i] = c;
			argv[1]++;
		}
		i = 0;
		int mark = 0;
		while (order[i])
		{
			if (mark == 1)
			{
				printf(", ");
				mark = 0;
			}
			printf("%d%c", count[(int)order[i]], order[i]);
			mark = 1;
			i++;
		}
	}
	printf("\n");
}
