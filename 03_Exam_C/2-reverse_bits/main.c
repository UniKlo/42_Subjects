
unsigned char	reverse_bits(unsigned char octet);

int	main(int argc, char **argv)
{
  if (argc == 2)
    printf(reverse_bits(*argv[1]));
  else
    printf("Wrong Input.");
  return (0);
}
