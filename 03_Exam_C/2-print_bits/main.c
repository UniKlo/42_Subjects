void	print_bits(unsigned char octet);

int	main(int argc, char **argv)
{
  if (argc == 2)
    print_bits(*argv[1]);
  return (0);
}
