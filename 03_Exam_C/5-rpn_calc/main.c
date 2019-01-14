/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:19:43 by khou              #+#    #+#             */
/*   Updated: 2019/01/13 18:22:49 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "do_op.h"

int		len_nbr(int nbr)
{
	int		len;
	
	len = 0;
	while (nbr)
	{
		nbr/= 10;
		len++;
	}
	return (len);
}

void	rpn_cal(char *str)
{
	int		i;
	int		top;
	int		stack[BUFF_SIZE];
	fun_table	f;

	top = -1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			stack[++top] = atoi(str);
			str += len_nbr(stack[top]);
		}
		if (*str == '+' || *str == '-' || *str == '*' || *str == '/')
		{
			if ((top - 2) < -1)
			{
				top -= 2;
				break;
			}
			if((f = dispatch(*str)) != NULL)
			{
				i = f(stack[top - 1], stack[top]);
				stack[--top] = i;
			}
		}
		str++;
	}
	if (top != 0)
		printf("Error\n");
	else
		printf("%d\n", stack[top]);
}
int		main(int argc, char **argv)
{
	if (argc == 2)
		rpn_cal(argv[1]);
	else
		printf("Error\n");
	return (0);
}
