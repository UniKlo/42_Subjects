/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence_v1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:14:13 by khou              #+#    #+#             */
/*   Updated: 2019/08/18 00:31:42 by khou             ###   ########.fr       */
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
	if (!tree)
		return (0);
	longest_sequence(tree->left);
	longest_sequence(tree->right);
	
	return (1);
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
    printf("max: %d\n", longest_sequence(tree));


/*  t_node tree[8];

    tree[0].value = 5;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].value = 6;
    tree[1].left = NULL;
    tree[1].right = NULL;

    tree[2].value = 6;
    tree[2].left = &tree[3];
    tree[2].right = &tree[4];

    tree[3].value = 7;
    tree[3].left = &tree[5];
    tree[3].right = &tree[6];

    tree[4].value = 3;
    tree[4].left = NULL;
    tree[4].right = &tree[7];

    tree[5].value = 3;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].value = 2;
    tree[6].left = NULL;
    tree[6].right = NULL;

    tree[7].value = 2;
    tree[7].left = NULL;
    tree[7].right = NULL;

    t_node tree2[1]; tree2[0].value = 1;
    tree2[0].left = tree2[0].right = 0;
    printf("max: %d\n", longest_sequence(tree2));
*/
}

