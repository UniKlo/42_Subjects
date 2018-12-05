/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:05:13 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 10:25:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

int		main(int argc, char **argv)
{
	char	map[5000][5000];
	int i = 0;
	int n = 1;
	int j;
	printf("here");
	while (n < argc)
	{
		j = 0;
		while(*argv[n])
			map[i][j++] = *argv[n]++;
		map[i][j] = '\0';
		printf("%s\n", map[i]);
		i++;
		n++;
	}
/*
//	map[i] = NULL;
	write (1 , "herr", 4);
	printf("here");
	printf("%s\n", map[0]);
	j = 0;
	while (j < i)
		printf("%s\n", map[j++]);
*/
}
