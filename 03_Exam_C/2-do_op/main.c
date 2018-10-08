#include "do_op.h"

int	add(int a, int b){
  int	ret = a + b;
  return (ret);}

int	deduction(int a, int b){
  int ret = a - b;
  return (ret);}

int	production(int a, int b){
  int ret  = a * b;
  return (ret);}

int	divide(int a, int b){
  int ret = a / b;
  return (ret);}

int 	mode(int a, int b){
  int ret = a % b;
  return (ret);}

fun_table	dispatch(char c)
{
  fun_table	f[126];

  f['+'] = &add;
  f['-'] = &deduction;
  f['*'] = &production;
  f['/'] = &divide;
  f['%'] = &mode;
  return (f[(int) c]);
}


int	main(int argc, char **argv)
{
  fun_table	f;
  if (argc == 4)
    {
      if((f = dispatch(*argv[2])) != NULL)
	printf("%d", f(atoi(argv[1]), atoi(argv[3])));
    }
  printf("\n");
  return (0);
}
