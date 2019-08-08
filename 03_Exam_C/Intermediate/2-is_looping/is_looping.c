/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:04:20 by khou              #+#    #+#             */
/*   Updated: 2019/08/07 22:20:57 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
	int value;
	struct s_node *next;
} t_node;

int	is_looping(struct s_node *node)
{
	t_node *cmp = node;
	while (cmp)
	{
		if (node == cmp)
			return (1);
		node = node->next;
		cmp = cmp->next->next;
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

	printf("%d\n", is_looping(root));
	
}
*/
