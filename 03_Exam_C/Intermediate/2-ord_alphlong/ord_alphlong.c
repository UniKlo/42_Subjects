#include <stdio.h>
#include <unistd.h>

int str_len(char *str)
{
  int l = 0;
  while (*str)
    {
      l++;
      str++;
    }
  return (l);
}

int             main(int argc, char **argv)
{

  if (argc > 1)
    {
      int i = 1;
      int     len = 0;
      int min_len = str_len(argv[i]);
      char *min_str = argv[1];
      while (i < argc)
	{
	  len = str_len(argv[i]);
	  //                      printf("len of str: %d %s\n", len, argv[i]);
	  if (min_len > len)
	    {
	      min_len = len;
	      min_str = argv[i];
	    }
	  //                      printf("min_len: %d, %s\n", min_len, min_ID);
	  i++;
	}
      printf("min_len: %d, %s\n", min_len, min_str);
      /*
      int count = min_len;
      while (count)
	{
	  int beg = 0;
	  int end = min_len - 1;
	  while (beg < min_len)
	    {
	      end = beg + count - 1;
	      if (end < min_len)
		{
		  printf("main: beg: \
		  %d, end: %d\n", beg, end);
                                  int found =  str_array_cmp(beg, end, min_str, argv,\
 argc - 1);
                                  //printf("found: %d\n", found);
                                  if (found == 1)
                                    return (0);
                                }
                                beg++;
                        }
                        count--;
                }
                write(1, "\n", 1);
      */
        }
        else
	write(1, "\n", 1);
}
