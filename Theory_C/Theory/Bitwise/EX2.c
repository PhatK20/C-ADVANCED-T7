// Note that the output of the following
// program is compiler dependent
#include <stdio.h>

int main()
{
	unsigned int x = 1;
	printf("Signed Result %d \n", ~x);
	printf("Unsigned Result %ud \n", ~x);
	return 0;
}
