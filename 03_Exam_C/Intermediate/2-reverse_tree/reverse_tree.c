/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:01:48 by exam              #+#    #+#             */
/*   Updated: 2019/07/23 10:28:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
    if (!root)
        return ;
	struct s_node *tmp;

	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}
/*
#include <stdlib.h>
#include <stdio.h>

void	print_tree(struct s_node *root)
{
	if (!root)
		return ;
	printf("%d\n", root->value);
	print_tree(root->left);
	print_tree(root->right);
}

struct s_node *new_node(int nbr)
{
	struct s_node *new;
	new = malloc(sizeof(struct s_node));

	new->value = nbr;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

int		main()
{
	struct s_node *root;

	root = new_node(94);
	root->left = new_node(34);
	root->right = new_node(52);

	root->left->left = new_node(1);
	root->left->right = new_node(99);

	root->left->left->left = new_node(20);
	root->left->right->left = new_node(83);
	root->left->right->right = new_node(39);

	print_tree(root);
	printf("after\n");
	reverse_tree(root);
	print_tree(root);
}
*/
