#ifndef __LINKLIST_H
#define __LINKLIST_H


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

//单链表结构

typedef int ElemType;

//结点类型

typedef struct Node
{
    ElemType  data;
    struct Node *next;
}Node;

//带头结点

typedef struct LinkList
{
    struct Node head;
    int count;
}LinkList, *pList;

void InitLinkList(pList list);//初始化单链表

void InsertElemToList(pList list, ElemType val, int pos);//插入数据函数

void DeleteElemOfList(pList list, int pos);//删除数据函数

void Destroylist(pList list);//销毁函数

void ShowList(pList list);//打印函数

#endif

