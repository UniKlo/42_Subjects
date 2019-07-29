#include <stdlib.h>

struct s_node {
  void          *content;
  struct s_node *next;
};

struct s_stack {
  struct s_node *top;
};

struct s_stack *init()
{
  struct s_stack *s;
  s = malloc(sizeof (struct s_stack));
  s->top = NULL;
  return (s);
}

int	isEmpty(struct s_stack *s)
{
  if (!s || !s->top || !s->top->content)
    return (1);
  return (0);
}
void	*pop(struct s_stack *s)
{
  struct s_node *tmp;
  void *content;
  if (!s || !s->top)
    return (NULL);
  tmp = s->top;
  content = s->top->content;
  s->top = s->top->next; 
  free(tmp);
  return (content);
}

void	*peek(struct s_stack *s)
{
  if (!s || !s->top)
    return (NULL);
  return (s->top->content);
}

void	push(struct s_stack *s, void *content)
{
  if (!s)
    return ;
  struct s_node *top;
  top = malloc(sizeof(struct s_node));
  top->content = content;
  top->next = s->top;
  s->top = top; 
}
#include <stdio.h>
int	main()
{
  struct s_stack *q;
  q = init();
  printf("is Enpty: %d\n", isEmpty(q));
  printf("Poping: %s\n", pop(q));
  printf("Peeking: %s\n", peek(q));

  printf("Pushing one\n"); push(q, "one");
  printf("Peeking: %s\n", peek(q));
  printf("isEmpty: %i\n", isEmpty(q));
  printf("Pushing two\n"); push(q, "two");
  printf("Peeking: %s\n", peek(q));
  printf("isEmpty: %i\n", isEmpty(q));
  printf("Pushing three\n"); push(q, "three");
  printf("Peeking: %s\n", peek(q));
  printf("isEmpty: %i\n", isEmpty(q));

  printf("Poping: %s\n", pop(q));
  printf("isEmpty: %i\n", isEmpty(q));
  printf("Peeking: %s\n", peek(q));
  printf("Poping: %s\n", pop(q));
  printf("isEmpty: %i\n", isEmpty(q));
  printf("Peeking: %s\n", peek(q));
  printf("Poping: %s\n", pop(q));
  printf("isEmpty: %i\n", isEmpty(q));
  printf("Peeking: %s\n", peek(q));
  printf("Poping: %s\n", pop(q));
  printf("isEmpty: %i\n", isEmpty(q));
  printf("Peeking: %s\n", peek(q));

}
