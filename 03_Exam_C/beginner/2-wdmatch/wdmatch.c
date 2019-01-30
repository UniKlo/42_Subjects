/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:18:13 by khou              #+#    #+#             */
/*   Updated: 2018/10/05 15:34:08 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *s)
{
	while (*s)
		write (1, s++, 1);
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		char *beg = argv[1];
		while (*argv[2])
		{
			if (*argv[1] == *argv[2])
				argv[1]++;
			else
				argv[2]++;
		}
		if (!*argv[1])
			putstr(beg);
	}
	write (1, "\n", 1);
	return (0);
}
