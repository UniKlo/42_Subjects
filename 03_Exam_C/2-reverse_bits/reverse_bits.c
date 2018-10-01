unsigned char	reverse_bits(unsigned char octet)
{
    int			cmp;
    unsigned char	new;
  
    cmp = 1;
    new = 0;
    while (cmp <= 128)
	{
	    new = new | (octet & cmp);
	    cmp <= 2;
	}
    return (new);
}
