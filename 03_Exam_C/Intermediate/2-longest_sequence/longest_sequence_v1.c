/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence_v1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:14:13 by khou              #+#    #+#             */
/*   Updated: 2019/08/18 16:12:48 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
}     t_node;

int max_nbr(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int	longest_sequence(t_node *tree)
{
	int l = 0;
	int r = 0;
	if (!tree)
		return (1);
	l = longest_sequence(tree->left);
	r = longest_sequence(tree->right);
	if (tree->left)
	{
		if (tree->left->value == tree->value + 1)
			l += 1;
	}
	else if (tree->right)
	{
		if (tree->right->value == tree->value + 1)
			r += 1;
	}
	printf("tree: %d, l: %d, r: %d, max:%d\n", tree->value, l , r, max_nbr(l, r));
	
	return (max_nbr(l, r));
	
}

#include <stdlib.h>

t_node *new_node(int n)
{
	t_node *new = malloc(sizeof(t_node));

	new->value = n;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	print_tree(t_node *root)
{
	if (!root)
		return ;
	print_tree(root->left);
	print_tree(root->right);
		printf("%d\n", root->value);

}

int main()
{

    t_node *tree = new_node(10);

    tree->left = new_node(5);

    tree->left->left = new_node(6);
	tree->left->right = new_node(9);

    tree->left->left->left = new_node(7);
    tree->left->left->right = new_node(13);

	print_tree(tree);
    printf("tree max: %d\n", longest_sequence(tree));

	t_node *tree1 = new_node(5);

	tree1->left = new_node(6);
	tree1->right = new_node(4);

	tree1->right->left = new_node(9);
	tree1->right->right = new_node(3);

	tree1->right->left->left = new_node(3);
	tree1->right->left->right = new_node(2);

	tree1->right->right->right = new_node(2);
	printf("tree1 max: %d\n", longest_sequence(tree1));
    t_node tree2[1]; tree2[0].value = 1;
    tree2[0].left = tree2[0].right = 0;
    printf("tree2 max: %d\n", longest_sequence(tree2));

}

