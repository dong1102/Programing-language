#ifndef __CYCDOULIST_H
#define __CYCDOULIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;
//结点
typedef struct CycNode
{
    struct CycNode *prev;
    ElemType data;
    struct CycNode *next;
}CycNode;

//链表

typedef struct CycDouList
{
    CycNode *head;
    int count;
}CycDouList, *pCycList;

void InitCycDouList(pCycList list);//初始化函数

void InsertCycDouList(pCycList list, ElemType value, int pos);//插入函数


#endif