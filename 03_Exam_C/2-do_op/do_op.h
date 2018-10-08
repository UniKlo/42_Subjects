#ifndef DO_OP_H
# define DO_OP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef int	(*fun_table)(int a, int b);

fun_table	dispatch(char c);
#endif
