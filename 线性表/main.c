#include "SqList.h"


int main()
{
	//  结构体变量  elem  length  listsize
	SqList list;  
	InitSqList(&list);

	//void InitSqList(SqList *list);//构建空线性表

	//int InsertSqList(SqList *list, int pos, int val);// 在顺序表的指定位置pos插入数据val

	//int InsertHead(SqList *list, int val);// 在顺序表的第一个位置插入数据

	//int InsertTail(SqList *list, int val);// 在顺序表的最后一个位置插入数据

	//int DeleteSqList(SqList *list, int pos);// 删除指定位置的数据

	//int DeleteHead(SqList *list);// 删除第一个数据元素

	//int DeleteTail(SqList *list);// 删除最后一个数据元素

	//int FindVal(SqList *list, int val);// 查找val所在的位置(最后一次出现的位置)

	InsertSqList(&list, 3, 10);

	DestroySqList(&list);
}