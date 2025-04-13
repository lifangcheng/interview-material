#include <stdio.h>

int opp(int a)
{
	return a ^ (  (1<<12) || (1<<13) || (1<<14) );
}

int main(int argc, char **argv)
{
	int a=0;
	printf("%d\n", a);
	
	a = opp(a);
	printf("%d\n", a);
	return 0;
}
