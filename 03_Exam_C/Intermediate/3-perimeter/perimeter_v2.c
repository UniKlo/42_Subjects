#include <stdio.h>

struct s_node {
  int           value;
  struct s_node *right;
  struct s_node *left;
};

void	print_node(struct s_node *root)
{
  printf("%d ", root->value);
}

void print_left(struct s_node *root)
{
  if (!root || !root->left)
    return ;
  printf("%d ", root->value);
  print_left(root->left);
}
void	print_leaf(struct s_node *root)
{
  if (!root)
    return ;
  if (!root->left && !root->right)
    {
      printf("%d ", root->value);
    }
  print_leaf(root->left);
  print_leaf(root->right);
}

void print_right(struct s_node *root)
{
  if (!root || !root->right)
    return ;
  print_right(root->right);
  printf("%d ", root->value);;
}

void perimeter(struct s_node *root)
{
  if (!root)
    return ;
  print_node(root);
  print_left(root->left);
  print_leaf(root);
  print_right(root->right);
  printf("\n");

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
  root->left->left->left = new_node(1000);

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
