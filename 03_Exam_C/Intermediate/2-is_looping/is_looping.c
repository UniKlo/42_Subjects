/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:26:25 by khou              #+#    #+#             */
/*   Updated: 2019/08/19 22:33:49 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
	int value;
	struct s_node *next;
} t_node;

int	is_looping(struct s_node *node)
{
	t_node *cmp = node;
	int mark = 0;
	if (!node)
		return (0);
	while (cmp && node)
	{
		if (node == cmp)
		{
			if (mark == 0)
				mark = 1;
			else
				return (1);
		}
		node = node->next;
		if (cmp->next->next)
			cmp = cmp->next->next;
		else
			return (0);
	}
	return(0);
}

/*
#include <stdio.h>
#include <stdlib.h>
t_node	*new_node(int n)
{
	t_node *new;
	new = malloc(sizeof(t_node));
	new->value = n;
	new->next = NULL;
	return (new);
}
int		main()
{
	t_node *root;
	root = new_node(1);
	root->next = new_node(2);
	root->next->next = new_node(3);
	root->next->next->next = new_node(4);
	root->next->next->next->next = new_node(5);
	root->next->next->next->next->next = new_node(6);
	root->next->next->next->next->next->next = root->next;
	printf("is Loop: %d\n", is_looping(root));
	t_node *root1;
    root1 = new_node(1);
    root1->next = new_node(2);
    root1->next->next = new_node(3);
    root1->next->next->next = new_node(4);
    root1->next->next->next->next = new_node(5);
    root1->next->next->next->next->next = new_node(6);
    printf("not loop: %d\n", is_looping(root1));
}
*/
