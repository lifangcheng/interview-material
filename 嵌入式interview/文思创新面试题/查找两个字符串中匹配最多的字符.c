/*****************************************************************
	功能：【查找两个字符串中能连续匹配上最多的字符】
	      如"abcd"和"aogabc"，匹配最多的是abc三个字符，
	      将这三个字符输出。
		  用'\0'判断结束，避免了使用string.h中的strlen
	日期：2009.12.29
	作者：DC（有问题请留言）
*****************************************************************/

#include <stdio.h>
void search_char(char *p, char *q)
{
	/******************************************************************************
		三层循环，第一层：p中从第0个字符开始
		          第二层：q中从第0个字符开始
				  第三层：p中第i个字符在q中某个j的位置找到后，用pos记录位置，
				  进入此循环，此循环继续往下匹配，sum++，如果发现不匹配，
				  判断sum是否大于记录的最大匹配数量sum_max，
				  如果大于，sum_max=sum；pos_max=pos;
				  退出第三层循环。j继续增加，即从上次找到的pos的下一个字符开始去匹配。
	*********************************************************************************/
	int i,j,k; 
	
	/*****************************
	记录位置和匹配上的总数，
	当匹配总数超过上次匹配上的总数，
	给相应的max赋值。
	******************************/
	int pos,pos_max,sum=0, sum_max=0; 
	
	for (i=0; *(p+i)!='\0'; i++)
	{
		for(j=0; *(q+j)!='\0'; j++)
		{	
			/*从p中依次选字符去跟q中的字符匹配*/
			if( *(p+i) == *(q+j) ) //匹配上的话，立即进入第三层循环
			{
				pos = j;
				for(k=j; (*(q+k)!='\0') && (*(p+i+(k-j))!='\0'); k++) //从q中与p匹配上的第一个字符开始往下找
				{
					if ( *(p+i+(k-j)) != *(q+k) )
						break;
					sum++;
				}
				if(sum > sum_max) //循环结束后，判断本次匹配上的字符个数是不是比上次匹配上的还多
				{
					pos_max = pos;   //最大的起始位置
					sum_max = sum;   //匹配上的字符个数（根据这个就知道匹配终止的位置了）
				}
				sum = 0;
			}
		}
	}
	
	/*把找到的位置和匹配的字符数量变成相应的位置*/
	for (i=pos_max;i<pos_max+sum_max;i++)
	{
		putchar(*(q+i));
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	char *p = "the procedure named 'hello world' is used in many(different language) programs!";
	char *q = "I want to search for the worlds(different language), usa the function named search_char!!!";
	search_char(p, q);
	
	return 0;
}