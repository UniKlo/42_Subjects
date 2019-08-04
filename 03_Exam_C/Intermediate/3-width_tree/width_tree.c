#include <stdio.h>

struct s_node {
  int           value;
  struct s_node *right;
  struct s_node *left;
};

int	count_long(struct s_node *root)
{
  int i = 0;
  int j = 0;
  int max = 0;
  if (!root)
    return (0);
  i = count_long(root->left);
  j = count_long(root->right);
  if (i > j)
    max = i;
  else
    max = j;
  return (max + 1);
}

int	width_tree(struct s_node *root)
{
  int ret = 0;
  ret = count_long(root->left) + count_long(root->right) + 1;
  return (ret);
}

#include <stdlib.h>

void	print_tree(struct s_node *root)
{
  if (!root)
    return ;
  printf("%d ", root->value);
  print_tree(root->left);
  print_tree(root->right);
}

struct s_node *new_node(int n)
{
  struct s_node *new_node;

  new_node = malloc(sizeof(struct s_node));

  new_node->value = n;
  new_node->left = NULL;
  new_node->right = NULL;

  return (new_node);
}

int	main()
{
  struct s_node *root;

  root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(5);
  root->left->left = new_node(3);
  root->left->right = new_node(4);
  root->left->right->left = new_node(6);

  root->right->left =new_node(7);
  root->right->right =new_node(8);
  print_tree(root);

  printf("the width is: %d\n", width_tree(root));
}
