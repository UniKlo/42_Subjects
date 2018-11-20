/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:51:27 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 12:52:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int len(char *str)
{
    int l = 0;
    while (*str++)
        l++;
    return (l);
}

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
	int  j = 0;
	int beg = 0;
	int word;

	if (argc >= 2)
	{
		while (argv[1][j])
		{
            if(j != beg && word == 2)
                write(1, " ", 1);
			while (argv[1][j] && is_space(argv[1][j]))
                j++;
			if(word == 3)
                write(1, " ", 1);
			while (argv[1][j] && !is_space(argv[1][j]) && word != 2)
            {
                word = 1;
				j++;
			}
			if (word == 1)
			{
				beg = j;
				word = 2;
			}
			while (argv[1][j] && !is_space(argv[1][j]) && word == 2)
			{
				write(1, &argv[1][j], 1);
				j++;
			}
		}
		if (!is_space(argv[1][j - 1]) && j != beg)
			write(1, " ", 1);
		j = 0;
		while(j < beg)
		{
			while (argv[1][j] && is_space(argv[1][j]))
                j++;
			write(1, &argv[1][j++], 1);
		}

	}
	write(1, "\n", 1);
}
