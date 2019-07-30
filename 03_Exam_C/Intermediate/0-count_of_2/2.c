



int count_of_2(int n) {
	int count = 0;
	for (int i = 0; i <= n; ++i)
	{
		int tmp = i;
		while (tmp > 0)
		{
			if (tmp % 10 == 2) ++count;
			tmp /= 10;
		}
	}
	return (count);
}


//test 
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av){
	printf("%i\n", count_of_2(atoi(av[1])));	
}
