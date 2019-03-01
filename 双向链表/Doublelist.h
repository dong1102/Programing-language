#ifndef __DOUBLELIST_H
#define __DOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;

// 结点结构

typedef struct Node
{
    struct Node *prev;
    ElemType  data;
    struct Node *next;
}Node;

typedef struct DoubleList
{
    Node head;
    int count;
}DoubleList, *pList;

void InitDoubleList(pList list);//初始化函数

void ShowDoubleList(pList list);//打印函数

void ReverseShow(pList list);//逆序打印函数

void InsertDoubleList(pList list, ElemType val, int pos);//插入函数

void DeleteDoubleList(pList list, int pos);//删除函数

void DestroyList(pList list);//清空函数



#endif