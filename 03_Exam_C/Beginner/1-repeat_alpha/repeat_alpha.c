/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:45:08 by khou              #+#    #+#             */
/*   Updated: 2018/11/27 22:55:25 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i])
		{
			int count = 0;
			if ('a' <= argv[1][i] && argv[1][i] <= 'z')
				count = argv[1][i] + 1  - 'a';
			else if ('A' <= argv[1][i] && argv[1][i] <= 'Z')
				count = argv[1][i] + 1  - 'A';
			else
				count = 1;
			while (count--)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
