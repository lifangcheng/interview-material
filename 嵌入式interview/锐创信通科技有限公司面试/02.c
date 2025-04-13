#include <stdio.h>
#define OVER_FLOW -2
#define OK         1

typedef int ElemType; /*定义数据类型*/

typedef struct node_data /*定义链表数据节点的结构体*/
{
	ElemType data;
	struct node_head *prior;
	struct node_data *next;
} DNode;

typedef struct node_head /*定义链表头尾节点的结构体，D表示double，双向链表*/
{
	DNode *Head;
	DNode *Tail;
} DLinkNode, *DLinkList;

/*建立一个空的双向链表，没有节点，只有头、尾指针*/
void Init_DLinkList(DLinkList HT_pointer)
{
	HT_pointer->Head = NULL;
	HT_pointer->Tail = NULL;
}

/*在表头插入一个元素*/
int Insert_First(DLinkList HT_pointer, ElemType x)
{
	DNode *p, *q;
	p = (DNode *) malloc(sizeof(DNode));
	if (p == NULL)
		return OVER_FLOW;
		
	p->data = x;
	
	if (HT_pointer->Head == NULL)
	{ /*链表为空*/
		p->prior = NULL; //新节点的前驱指针指向NULL
		p->next  = NULL; //新节点的后继指针指向NULL
		HT_pointer->Head = p; //头指针指向新节点
		HT_pointer->Tail = p; //尾指针指向新节点
	}
	else
	{ /*链表不空*/
		p->prior = NULL;
		p->next = HT_pointer->head; //新节点后继指针指向原来那个头结点
		HT_pointer->Head->prior = p; //原来节点的前驱指针指向新节点
		HT_pointer->Head = p; //原来的头指针指向新节点
	}
	return OK;
}

/*删除一个元素*/
int Delete_DLinkList(DLinkList HT_pointer, ElemType x)
{
	DNode *p, *q;
	p = HT_pointer->head; /*p取头指针*/
	while(p != NULL)
	{
		printf("* %d", p->data);
		if (p->data == x)
		{	/*如果双向链表中只剩下1个节点*/
			if (HT_pointer->Head == p && HT_pointer->Tail == p)
			{
				HT_pointer->Head = NULL; //头指针指向NULL
				HT_pointer->Tail = NULL; //尾指针指向NULL
				//free(p); /*我总感觉这个p不在这里free，因为第85行还free了一次*/
			}
			else if (HT_pointer->head == p)
			{	/*删除的是双向链表中的头结点*/
				HT_pointer->Head = p->next;
				p->next->prior = NULL;
			}
			else if (HT_pointer->Tail == p)
			{	/*删除的是双向链表中的尾节点*/
				HT_pointer->Tail = p->prior;
				p->prior->next = NULL;
			}
			else
			{	/*中间的节点*/
				p->next->prior = p->prior;
				p->prior->next = p->next;
			}
			free(p); //释放节点空间
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

int main(int argc, char *argv[])
{
	DLinkNode HeadTail;
	ElemType x;
	Init_DLinkList (&HeadTail);
	
	x = 30;
	Insert_first(&HeadTail, x);
	Delete_DLinkList(&HeadTail, x);
	
	return 0;
}