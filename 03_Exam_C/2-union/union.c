/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:53:36 by khou              #+#    #+#             */
/*   Updated: 2018/10/14 21:58:08 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	char str[123];
	
	if(argc == 3)
	{
		while(*argv[1])
		{
			if (!str[(int)*argv[1]])
			{
				str[(int)*argv[1]] = 1;
				write (1, argv[1], 1);
			}
			argv[1]++;
		}
		while(*argv[2])
		{
			if (!str[(int)*argv[2]])
            {
                str[(int)*argv[2]] = 1;
                write (1, argv[2], 1);
			}
			argv[2]++;
        }
	}
	write(1, "\n", 1);
	return (0);
}
