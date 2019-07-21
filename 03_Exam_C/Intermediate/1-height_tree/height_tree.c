#include <stdlib.h>
#include <stdio.h>

struct s_node {
  int           value;
  struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
  if (!root)
    return(0);


  int i = 0;
  int h = 0;
  int max = 0;
    while (root->nodes[i])
    {
      h = 0;
      printf("step1: nodes[%d]: %d\n", i,root->nodes[i]->value);
      h = height_tree(root->nodes[i]) + 1;
      printf("h: %d, max: %d\n", h, max);
      if (h > max)
	max = h;
      i++; 
      }
  return (max);
}

struct s_node *new_node(int val)
{
  struct s_node *node = malloc(sizeof(struct s_node));

  node->value = val;
  node->nodes = malloc(sizeof(struct s_node) * 42);
  node->nodes[41] = NULL;
  return (node);
}

int	main()
{
  struct s_node *root;

  root = new_node(94);
  root->nodes[0] = new_node(34);
  root->nodes[1] = new_node(52);

  root->nodes[0]->nodes[0] = new_node(1);
  root->nodes[0]->nodes[1] = new_node(99);
  root->nodes[0]->nodes[2] = new_node(68);

  root->nodes[1]->nodes[0] = new_node(11);
  root->nodes[1]->nodes[1] = new_node(12);

  root->nodes[1]->nodes[0]->nodes[0] = new_node(13);
  root->nodes[1]->nodes[0]->nodes[0]->nodes[0] = new_node(87);

  printf("height: %d\n", height_tree(root));
}
