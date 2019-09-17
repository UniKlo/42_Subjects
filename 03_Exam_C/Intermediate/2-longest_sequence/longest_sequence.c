/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:34:06 by exam              #+#    #+#             */
/*   Updated: 2019/09/10 10:20:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
}			t_node;

int max = 0;

int cur_sequence(t_node *node)
{
	if (!node)
		return (0);
	int l = cur_sequence(node->left) + 1;
	int r = cur_sequence(node->right) + 1;

	if (node->left)
	{
		if (node->value + 1 != node->left->value)
			l = 1;
	}
    if (node->right)
    {
        if (node->value + 1 != node->right->value)
            r = 1;
    }
	max = l > max ? l : max;
	max = r > max ? r : max;
	int cur = l > r ? l : r;
	return (cur);
}

int	longest_sequence(struct s_node *node)
{
	if (!node)
		return (0);
	cur_sequence(node);
	return (max);
}
/*
#include <stdlib.h>
#include <stdio.h>

t_node	*new_node(int nbr)
{
	t_node *new = malloc(sizeof(t_node));

	new->value = nbr;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	print_tree(t_node *tree)
{
	if (!tree)
		return ;
	print_tree(tree->left);
	printf("%d\n", tree->value);
	print_tree(tree->right);
}

int main()
{
	t_node *root = new_node(10);

	root->left = new_node(5);
	root->left->left = new_node(6);

	root->left->right = new_node(9);
	root->left->right->right = new_node(10);
	root->left->right->right->right = new_node(11);

	print_tree(root);
	printf("T/F: %d\n", longest_sequence(root));

	max = 0;
	t_node *root1 = new_node(30);
	root1->left = new_node(15);
    root1->left->left = new_node(61);

	root1->left->right = new_node(41);
    root1->left->right->left = new_node(80);
    print_tree(root1);
    printf("T/F: %d\n", longest_sequence(root1));
}
*/
