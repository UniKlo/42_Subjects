/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:17:42 by khou              #+#    #+#             */
/*   Updated: 2019/01/15 18:33:10 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		len_nbr(int nbr)
{
	int		len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr/= 10;
		len++;
	}
	return (len);
}

int		operate(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '*')
		return (a * b);
	else if (c == '/')
		return (a / b);
	else if (c == '%')
		return (a % b);
	return (0);
}

void	rpn_cal(char *str)
{
	int		tmp;
	int		top;
	int		stack[4000];

	top = -1;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') ||
			(*str == '-' && ( *(str + 1) >= '0' && *(str + 1) <= '9')))
		{
			stack[++top] = atoi(str);
			str += len_nbr(stack[top]);
		}
		else if (*str == '+' || *str == '-' || *str == '*' ||
				 *str == '/' || *str == '%')
		{
			if (top == 0)
			{
				top = 1;
				break;
			}
			else
			{
				tmp = operate(stack[top - 1], stack[top], *str);
				stack[--top] = tmp;
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
