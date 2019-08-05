/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 01:00:41 by khou              #+#    #+#             */
/*   Updated: 2019/08/05 01:01:01 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
    int value;
    struct s_node *right;
    struct s_node *left;
}               t_node;

t_node *first = 0;
t_node *last = 0;

void in_order(t_node *node)
{
    if (!node) return ;
    in_order(node->left);
    if (!first)
    {
        first = last = node;
    }
    else
    {
        node->left = last;
        last->right = node;
        last = node;
    }
    in_order(node->right);
}

struct s_node *convert_bst(struct s_node *root)
{
    in_order(root);
    first->left = last;
    last->right = first;
    return (first);
}

/*
#include <stdio.h>
#include <stdlib.h>

t_node *new_node(int value) {
    t_node *ret = malloc(sizeof(t_node));
    ret->value = value;
    ret->left = ret->right = 0;
    return (ret);
}

int main(){
    t_node *root = new_node(28);
    root->left = new_node(26);
    root->left->left = new_node(25);
    root->left->right = new_node(27);
    root->right = new_node(30);
    root->right->left = new_node(29);
    root->right->right = new_node(31);

     in_order(root);
    first->left = last; last->right = first;
    for(int i = 0; i < 50; ++i)
    {
        printf("%i ", first->value);
        first = first->left;
    }
    printf("\n");
}
*/
