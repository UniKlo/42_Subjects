/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:07:23 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 12:14:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};
/*
struct s_node *convert_bst(struct s_node *root)
{
    if (!root)
        return (NULL);
    convert_bst(root->left);
    convert_bst(root->right);

}
*/
#include <stdlib.h>
#include <stdio.h>

void    print_tree(struct s_node *root)
{
    if (!root)
		return ;
    print_tree(root->left); 
	printf("%d\n", root->value);
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


int     main()
{
    struct s_node *root;

    root = new_node(28);
    root->left = new_node(26);
	root->right = new_node(29);
    root->left->left = new_node(24);
    root->left->right = new_node(27);

    root->left->left->left = new_node(23);
    root->left->left->right = new_node(25);

    print_tree(root);
}
