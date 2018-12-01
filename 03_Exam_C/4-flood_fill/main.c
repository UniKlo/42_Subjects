/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:39:20 by khou              #+#    #+#             */
/*   Updated: 2018/11/28 11:05:29 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
#include <unistd.h>
#include <stdlib.h>

char	**make_area(char **zone)
{
	
}

int		main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}

	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	write(1, "\n", 1);
	print_tab(area);
	return (0);
}
