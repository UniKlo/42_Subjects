/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:09:18 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 11:47:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

<<<<<<< HEAD
void print_left(struct s_node *root)
{
	if (!root)
		return ;
	printf("%d ", root->value);
	print_left(root->left);
=======
#include <stdio.h>
void tree_left(struct s_node *root)
{
  if (!root)
    return ;
  printf("%d ", root->value);
  tree_left(root->left);
}

void tree_right(struct s_node *root)
{
  if (!root)
    return ;
  if (root->right)
    {
      tree_right(root->right);
      printf("%d ", root->value);
    }
}

void tree_leaf(struct s_node *root)
{
  if (!root)
    return ;
  tree_leaf(root->left);
  tree_leaf(root->right);
  if (!root->left && !root->right)
    {
      printf("%d ", root->value);
    }
>>>>>>> 3dd665f7a22609e99d22af811b3042fc21b34b1a
}

void print_lleaf(struct s_node *root, int swich)
{
<<<<<<< HEAD
	if (!root)
		return ;
	if(swich == 1 && !root->left && !root->right)
		printf("%d ", root->value);
	print_lleaf(root->left, swich);
	if(root->right)
		swich = 1;
	print_lleaf(root->right, swich);
}
=======
  if (!root)
    return ;
  tree_left(root);
  printf("\n");
  tree_leaf(root);
  printf("\n");
  tree_right(root);
>>>>>>> 3dd665f7a22609e99d22af811b3042fc21b34b1a

void print_rleaf(struct s_node *root, int swich)
{
    if (!root)
        return ;
    if(swich == 1 && !root->left && !root->right)
		printf("%d ", root->value);
    print_rleaf(root->left, swich);
    print_rleaf(root->right, swich);
    if(root->left)
        swich = 1;
}

void print_right(struct s_node *root)
{
    if (!root || !root->right)
        return ;
    print_right(root->right);
    printf("%d ", root->right->value);
}

void perimeter(struct s_node *root)
{
<<<<<<< HEAD
	if (!root)
		return ;
	print_left(root);
	print_lleaf(root->left, 0);
	print_rleaf(root->right, 0);
	print_right(root);
	printf("\n");

=======
  if (!root)
    return ;
  printf("%d\n", root->value);
  print_tree(root->left);
  print_tree(root->right);
>>>>>>> 3dd665f7a22609e99d22af811b3042fc21b34b1a
}


#include <stdlib.h>
#include <stdio.h>

void    print_tree(struct s_node *root)
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


int     main()
{
    struct s_node *root;

    root = new_node(92);
    root->left = new_node(85);
    root->left->left = new_node(79);

    root->left->left->right = new_node(10);
	root->left->left->right->left = new_node(96);

	root->right = new_node(26);
    root->right->right = new_node(64);
    root->right->right->left = new_node(40);
    root->right->right->right = new_node(78);

	root->right->right->left->left = new_node(88);
	root->right->right->left->right = new_node(10);
	root->right->right->left->left->left = new_node(12);
	root->right->right->left->left->right = new_node(55);

	root->right->right->left->left->left->left = new_node(58);
	root->right->right->left->left->right->left = new_node(58);
	root->right->right->left->left->right->right = new_node(41);

	root->right->right->left->right->left = new_node(52);
	root->right->right->left->right->right = new_node(87);
	root->right->right->left->right->left->left = new_node(22);
	root->right->right->left->right->left->right = new_node(35);
	root->right->right->left->right->right->right = new_node(31);
	root->right->right->right->left = new_node(2);
	root->right->right->right->left->left = new_node(55);
	root->right->right->right->left->right = new_node(99);
	root->right->right->right->right = new_node(85);
	root->right->right->right->right->right = new_node(51);
    print_tree(root);

    printf("after\n");
    perimeter(root);
}
