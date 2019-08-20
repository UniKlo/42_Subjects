/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:36:18 by khou              #+#    #+#             */
/*   Updated: 2019/08/19 22:45:50 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node 
{
  int value;
  struct s_node *left;
  struct s_node *right;
};

int	size_of_tree(struct s_node *root)
{
  int size = 0;

  if (!root)
    return (0);
  size = size_of_tree(root->right) + size_of_tree(root->left) + 1; 
  return (size);
}
int mark = 0;
int	half_size(struct s_node *root, int half)
{
  int size = 0;

  if (!root)
    return (0);
  size = half_size(root->right, half) + half_size(root->left, half) + 1;
  if (size == half)
    mark = 1;
  return (size); 
}

int	can_split(struct s_node *root)
{
  int size = 0;
  size = size_of_tree(root);
  if (size % 2 != 0)
    return (0);
  half_size(root, size/2);
  if (mark == 1)
    return (1);
  return (0);
}

/*

#include <stdlib.h>
#include <stdio.h>
struct s_node *new_node(int n)
{
  struct s_node *new_node;

  new_node = malloc(sizeof(struct s_node));
  new_node->value = n;
  new_node->left = NULL;
  new_node->right = NULL;
  return (new_node);
}

void	print_tree(struct s_node *root)
{
  if (!root)
    return ;
  print_tree(root->left);
  print_tree(root->right);
  printf("%d\n", root->value);
}

int	main()
{
  struct s_node *root;
  
  root = new_node(28);
  root->left = new_node(51);
  root->left->left = new_node(26);
  root->left->right = new_node(48);
  root->left->left->left = new_node(76);
  root->left->left->right = new_node(13);
  print_tree(root);

  printf("size of the tree: %d\n", size_of_tree(root));
  printf("can split: %d\n", can_split(root));
  mark = 0;
  struct s_node *root1;
  root1 = new_node(5);
  root1->left = new_node(1);
  root1->right = new_node(6);
  root1->right->left = new_node(7);
  root1->right->right = new_node(4);
  root1->right->left->left = new_node(3);
  root1->right->left->right = new_node(2);
  root1->right->right->right = new_node(8);
  print_tree(root1);

  printf("size of the tree: %d\n", size_of_tree(root1));
  printf("can split: %d\n", can_split(root1));
  
  mark = 0;
  struct s_node *root2;
  root2 = new_node(5);
  root2->left = new_node(1);
  print_tree(root2);

  printf("size of the tree: %d\n", size_of_tree(root2));
  printf("can split: %d\n", can_split(root2));

  
  return (0);
}
*/
