/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:42:20 by khou              #+#    #+#             */
/*   Updated: 2019/08/27 00:32:22 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int max_len = 0;

int	sequence(t_node *tree)
{
	int l = 0;
	int r = 0;
	if (!tree)
		return (0);
	l = sequence(tree->left);
	r = sequence(tree->right);
	if (tree->left)
	{
		if (tree->left->value == tree->value + 1)
			l += 1;
	}
	if (tree->right)
	{
		if (tree->right->value == tree->value + 1)
			r += 1;
	}
	if (!tree->left && !tree->right)
	{
		max_len = max_nbr(1, max_len);
		return (1);
	}
	max_len = max_nbr(max_nbr(l, r), max_len);
	return (max_nbr(l, r));
	
}

int longest_sequence(t_node *tree)
{
	if (!tree)
        return (0);
	sequence(tree);
	return (max_len);
}

/*
#include <stdlib.h>
#include <stdio.h>

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
//  print_tree(tree);
    printf("tree max: 3 == %d\n", longest_sequence(tree));
	max_len = 0;
    t_node *tree1 = new_node(5);
    tree1->left = new_node(6);
    tree1->right = new_node(4);
    tree1->right->left = new_node(9);
    tree1->right->right = new_node(3);
    tree1->right->left->left = new_node(3);
    tree1->right->left->right = new_node(2);
    tree1->right->right->right = new_node(2);
    printf("tree1 max: 2 == %d\n", longest_sequence(tree1));
	max_len = 0;
    t_node *tree2 = new_node(1);
    printf("tree2 max: 1 == %d\n", longest_sequence(tree2));
	max_len = 0;
	t_node *tree3 = NULL;
    printf("tree3 max: 0 == %d\n", longest_sequence(tree3));
	max_len = 0;
	t_node *tree4 = new_node(30);
    tree4->left = new_node(15);
    tree4->right = new_node(41);
    tree4->left->left = new_node(16);
    tree4->right->left = new_node(80);
    printf("tree4 max: 2 == %d\n", longest_sequence(tree4));
}
*/
