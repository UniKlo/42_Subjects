/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:07:26 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 19:40:53 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

#define BUFF_SIZE (4096)

static int	match_brackets(char a, char b)
{
	return ((a == '[' && b == ']') || (a == '{' && b == '}') \
				|| (a == '(' && b == ')'));
}

static int	check_brackets(char *str)
{
	int		i;
	int		top;
	int		stack[BUFF_SIZE];// nbr array

	i = 0;
	top = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			stack[++top] = str[i];//store ascii in stack nbr array
//			printf("f: %c, stack[%d]\n", (char)stack[top], top);
		}
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
//			printf("b: %c, stack[%d]\n", (char)stack[top], top);
			if (!match_brackets(stack[top--], str[i]))
				return (0);
		}
		i += 1;
	}
	return (!top);
}

int			main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 1)
		write(1, "\n", 1);
	while (--argc)
	{
		if (check_brackets(argv[++i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
