#ifndef __CYCLINKLIST_H
#define __CYCLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int ElemType;


// 结点结构
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;


// 单循环链表结构
typedef struct CycLinkList
{
    Node *head;
    int count;
}CycLinkList, *pCyc;

void InitCycList(pCyc list);//初始化单循环链表

void InsertCycList(pCyc list, ElemType val, int pos);//插入数据函数

void DeleteCycList(pCyc list, int pos);//删除数据函数

void ShowList(pCyc list);//打印函数

void DestroyList(pCyc list);//清空函数



#endif