#include <stdio.h>
/*
	功能：求2102! = 2102 * 2101 * 2100 * …… * 1=???
	输出结果：0
	原因：溢出。计算机能表示的最大整数不过64个2相乘(unsigned long)。
*/
int main(int argc, char **argv)
{
	unsigned long mul_num = 1;
	int i;
	for (i=2102; i>0; i--)
	{
		mul_num *= i;
	}
	printf("%lu\n", mul_num);
	
	return 0;
}
