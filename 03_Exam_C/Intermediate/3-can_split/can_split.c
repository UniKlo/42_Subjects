struct s_node 
{
  int value;
  struct s_node *left;
  struct s_node *right;
};

#include <stdio.h>

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
  printf("size: %d\n", size);
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
  printf("%d\n", root->value);
  print_tree(root->left);
  print_tree(root->right);
}

int	main()
{
  struct s_node *root;
  /*
  root = new_node(28);
  root->left = new_node(51);
  root->left->left = new_node(26);
  root->left->right = new_node(48);
  root->left->left->left = new_node(76);
  root->left->left->right = new_node(13);
  */
  root = new_node(5);
  root->left = new_node(1);
  root->right = new_node(6);
  root->right->left = new_node(7);
  root->right->right = new_node(4);
  root->right->left->left = new_node(3);
  root->right->left->right = new_node(2);
  root->right->right->right = new_node(8);
  print_tree(root);

  printf("size of the tree: %d\n", size_of_tree(root));
  printf("can split: %d\n", can_split(root));
  return (0);
}
