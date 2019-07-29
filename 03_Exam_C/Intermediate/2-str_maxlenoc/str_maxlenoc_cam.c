/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:04:15 by khou              #+#    #+#             */
/*   Updated: 2019/07/22 00:13:46 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//get the shortest string
//get the pattern of the string

#include <stdio.h>

int str_len(char *str)
{
	int l = 0;
	while (*str)
	{
		l++;
		str++;
	}
	return (l);
}

int		main(int argc, char **argv)
{
	
	if (argc > 1)
	{
		int i = 1;
		int	len = 0;
		int min_len = str_len(argv[i]);
		char *min_str = argv[1];
		while (i < argc)
		{
			len = str_len(argv[i]);
//			printf("len of str: %d %s\n", len, argv[i]);
			if (min_len > len)
			{
				min_len = len;
				min_str = argv[i];
			}
//			printf("min_len: %d, %s\n", min_len, min_ID);
			i++;			
		}
		printf("min_len: %d, %s\n", min_len, min_str);
		int count = min_len;
		while (count)
		{
			int beg = 0;
			int end = min_len - 1;
			while (beg < min_len)
			{
				end = beg + count - 1;
				if (end < min_len)
				{
					int n = beg;
					while (n <= end)
					{
						printf("%c", min_str[n]);
						n++;
					}
//					str_array_cmp(beg, end, min_str, );
					printf("\n");
				}
				beg++;
			}
			printf("\n");
			count--;
		}

	}
	else
		printf("\n");
}
