#include "SqList.h"


int main()
{
	//  �ṹ�����  elem  length  listsize
	SqList list;  
	InitSqList(&list);

	//void InitSqList(SqList *list);//���������Ա�

	//int InsertSqList(SqList *list, int pos, int val);// ��˳����ָ��λ��pos��������val

	//int InsertHead(SqList *list, int val);// ��˳���ĵ�һ��λ�ò�������

	//int InsertTail(SqList *list, int val);// ��˳�������һ��λ�ò�������

	//int DeleteSqList(SqList *list, int pos);// ɾ��ָ��λ�õ�����

	//int DeleteHead(SqList *list);// ɾ����һ������Ԫ��

	//int DeleteTail(SqList *list);// ɾ�����һ������Ԫ��

	//int FindVal(SqList *list, int val);// ����val���ڵ�λ��(���һ�γ��ֵ�λ��)

	InsertSqList(&list, 3, 10);

	DestroySqList(&list);
}