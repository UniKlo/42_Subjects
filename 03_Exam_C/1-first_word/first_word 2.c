/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:24:40 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 09:40:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (*argv[1] && i == 0)
		{
			if (is_space(*argv[1]))
				argv[1]++;
			while (*argv[1] && !is_space(*argv[1]))
			{
				i = 1;
				write (1, argv[1]++, 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
