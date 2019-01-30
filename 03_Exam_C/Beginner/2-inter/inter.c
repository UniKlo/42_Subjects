/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:09:20 by khou              #+#    #+#             */
/*   Updated: 2019/01/09 15:07:56 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char str[126];
	if(argc == 3)
	{
		int n = 0;
		
		while (n <= 126)
			str[n++] = 0;
			
		while (*argv[1])
		{
			int beg = 0;
			while (argv[2][beg])
			{
				if (*argv[1] == argv[2][beg])
				{
					if (!str[(int)*argv[1]])
					{
						str[(int)*argv[1]] = 1;
						write (1, argv[1], 1);
					}
				}
				beg++;
			}
			argv[1]++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
