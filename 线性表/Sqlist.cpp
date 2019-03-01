#include "SqList.h"

/*
	1、申请空间，并使list中elem指针指向这块空间
	2、将list中length与listsize设置初始值

	typedef struct
	{
		int *elem;   //  指向存储数据元素的空间的指针
		int length;  //  当前存储数据的个数
		int listsize;  //  当前分配的存储空间的大小
	}SqList;
*/

static int IsEmpty(SqList *list)//判断链表是否为空
{
	assert(list != NULL);

	if (list->length == 0)
	{
		return TRUE;
	}

	return FALSE;
}

static int IsFull(SqList *list)//判断链表是否已满
{
	assert(list != NULL);

	if(list->length == list->listsize)
	{
		return TRUE;
	}

	return FALSE;
}

static int ExpandSpace(SqList *list)//扩充链表
{
	assert(list != NULL);

	int i = 2;
	while(IsFull(list) == 0)
	{
		int *p = (int *)malloc(sizeof(int)* i * LEN);
		list->length = 0;
	    list->listsize = i * LEN;
		*p++ = *(list->elem)++;
		i++;
		free(p);
	}

}

//构建一个空线性表
void InitSqList(SqList *list)
{
	assert(list != NULL);

	list->elem = (int *)malloc(sizeof(int)* LEN);
	list->length = 0;
	list->listsize = LEN;
}

// 在顺序表的指定位置pos插入数据val
int InsertSqList(SqList *list, int pos, int val)
{
	if(pos < 1 || pos > list->length+1)
	{
		return FALSE;
	}
	if(list->length >= list->listsize)
	{
		ExpandSpace(list);
	}

	for(int i = 0;i < list->length + 1 - pos;i++)
	{
		list->elem[list->length+1] = list->elem[list->length];
		list->length--;
	}
	list->elem[pos] = val;

	
}

// 在顺序表的第一个位置插入数据
int InsertHead(SqList *list, int val)
{
	if(list->length >= list->listsize)
	{
		ExpandSpace(list);
	}
	for(int i = 0;i < list->length + 1;i++)
	{
		list->elem[list->length+1] = list->elem[list->length];
		list->length--;
	}
	list->elem[1] = val;

}

// 在顺序表的最后一个位置插入数据
int InsertTail(SqList *list, int val)
{
	if(list->length >= list->listsize)
	{
		ExpandSpace(list);
	}
	
	list->elem[list->length+1] = val;

}

// 删除指定位置的数据
int DeleteSqList(SqList *list, int pos)
{

	while(pos <= list->length)
	{
		list->elem[pos] = list->elem[pos+1];
		pos++;
	}

}

// 删除第一个数据元素
int DeleteHead(SqList *list)
{
	for(int i = 1;i <= list->length;i++)
	{
		list->elem[i] = list->elem[i+1];
	}
}

// 删除最后一个数据元素
int DeleteTail(SqList *list)
{
	list->elem[list->length] = NULL;
}

// 查找val所在的位置(最后一次出现的位置)
int FindVal(SqList *list, int val)
{
	int j = 0;
	for(int i = 1;i <= list->length;i++)
	{
		
		if(list->elem[i] == val)
		{
			j = i;
		}
	}
	return j;
}

//释放申请的动态内存
void DestroySqList(SqList *list)
{
	assert(list != NULL);

	free(list->elem);
	list->length = list->listsize = 0;
}