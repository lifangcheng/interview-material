#include <stdio.h>

int swap(int *a, int *b)
{
	int *p;
	*p = *a; /*问题在这里，野指针！！！*/
	*a = *b;
	*b = *p;
	
	return 0;
}

int main(void)
{
	int a=2, b=3;
	int *p, *q;
	p = &a;
	q = &b;
	swap(p,q);
	
	return 0;
}