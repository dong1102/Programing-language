#include "SqList.h"

/*
	1������ռ䣬��ʹlist��elemָ��ָ�����ռ�
	2����list��length��listsize���ó�ʼֵ

	typedef struct
	{
		int *elem;   //  ָ��洢����Ԫ�صĿռ��ָ��
		int length;  //  ��ǰ�洢���ݵĸ���
		int listsize;  //  ��ǰ����Ĵ洢�ռ�Ĵ�С
	}SqList;
*/

static int IsEmpty(SqList *list)//�ж������Ƿ�Ϊ��
{
	assert(list != NULL);

	if (list->length == 0)
	{
		return TRUE;
	}

	return FALSE;
}

static int IsFull(SqList *list)//�ж������Ƿ�����
{
	assert(list != NULL);

	if(list->length == list->listsize)
	{
		return TRUE;
	}

	return FALSE;
}

static int ExpandSpace(SqList *list)//��������
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

//����һ�������Ա�
void InitSqList(SqList *list)
{
	assert(list != NULL);

	list->elem = (int *)malloc(sizeof(int)* LEN);
	list->length = 0;
	list->listsize = LEN;
}

// ��˳����ָ��λ��pos��������val
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

// ��˳���ĵ�һ��λ�ò�������
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

// ��˳�������һ��λ�ò�������
int InsertTail(SqList *list, int val)
{
	if(list->length >= list->listsize)
	{
		ExpandSpace(list);
	}
	
	list->elem[list->length+1] = val;

}

// ɾ��ָ��λ�õ�����
int DeleteSqList(SqList *list, int pos)
{

	while(pos <= list->length)
	{
		list->elem[pos] = list->elem[pos+1];
		pos++;
	}

}

// ɾ����һ������Ԫ��
int DeleteHead(SqList *list)
{
	for(int i = 1;i <= list->length;i++)
	{
		list->elem[i] = list->elem[i+1];
	}
}

// ɾ�����һ������Ԫ��
int DeleteTail(SqList *list)
{
	list->elem[list->length] = NULL;
}

// ����val���ڵ�λ��(���һ�γ��ֵ�λ��)
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

//�ͷ�����Ķ�̬�ڴ�
void DestroySqList(SqList *list)
{
	assert(list != NULL);

	free(list->elem);
	list->length = list->listsize = 0;
}