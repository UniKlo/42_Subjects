#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	fill(char *buff, int nbr_byte,int map_w, int i, char c)
{
  if (i > nbr_byte || i < 0)
    return ;
  if (buff[i] == 88)
    {
      buff[i] = c;
      fill(buff, nbr_byte, map_w, i + 1, c);
      fill(buff, nbr_byte, map_w, i - 1, c);
      fill(buff, nbr_byte, map_w, i + map_w, c);
      fill(buff, nbr_byte, map_w, i - map_w, c);
    }
}

void flood_fill(char *buff, int nbr_byte, int map_w, int i, char c)
{
  if (i >= nbr_byte || i < 0)
    return ;
  fill(buff, nbr_byte, map_w, i, c);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    {
      printf("Wrong nbr of args\n");
      return (0);
    }
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    {
      printf("failed to open\n");
    }
  char buff[500000];
  int nbyte = 500000;
  int nbr_byte = read(fd, buff, nbyte);
  if (nbr_byte == -1)
    {
      printf("failed to read\n");
    }
  int i = 0;
  int map_w = 0; //map_with
  int find_nl = 0;
  while (buff[i]) //validation
    {
      printf("%c", buff[i]);
      if (buff[i] != 46 && buff[i] != 88 && buff[i] != 10)
	{
	  printf("invalide char\n");
	  return (0);
	}
      if (!find_nl)
	map_w++;
      if (buff[i] == 10)
	find_nl = 1;
      i++;
    }
  i = 0;
  int cmp = 0;
  int map_h = 1;
  while (buff[i]) //width
    {
      if (buff[i] != 10)
	cmp++;
      //      printf("cmp: %d\n", cmp);
      if (buff[i] == 10)
	{
	  map_h++;
	  if (++cmp == map_w)
	    cmp = 0;
	  else
	    {
	      printf("invalide map width\n");
	      return (0);
	    }
	}
      i++;
    }
  printf("\nnbr_byte: %d, map_width: %d, map_height: %d\n",nbr_byte, map_w, map_h);
  //width including nl, height is not index
  i = 0;
  char c = 48;
  while (buff[i])
    {
      if (buff[i] == 88)
	{
	  flood_fill(buff, nbr_byte, map_w, i, c);
	  i = -1;
	  c++;
	}
      i++;
    }
  i = 0;
  while (buff[i])
    {
      printf("%c", buff[i]);
      i++;
    }
  return (0);
}


