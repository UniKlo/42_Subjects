#include <stdio.h>

//strcmp
//have argv[1] different combaination
//cmp to the rest

int	str_cmp(char *word1, char *word2)
{
  int i = 0;
  while (word2[i])
    {
      int j = 0;
      while (word1[j] == word2[i] && word2[i] != '\0')
	{
	  j++;
	  i++;
	}
      if (!word1[j])
	return (1);
      else
	i = i - j;
      i++;
    }
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc > 1)
    {
      char *tmp;
      
      /*
      int j = 2;
      while (j < argc)
	{
	  if (!str_cmp(tmp, argv[j]))
	    //change tmp;
	    j++;
	}*/
	printf("%s", tmp);
    }
  printf("\n");
  return (0);
}
