#ifndef __DOUBLELIST_H
#define __DOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;

// ���ṹ

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

void InitDoubleList(pList list);//��ʼ������

void ShowDoubleList(pList list);//��ӡ����

void ReverseShow(pList list);//�����ӡ����

void InsertDoubleList(pList list, ElemType val, int pos);//���뺯��

void DeleteDoubleList(pList list, int pos);//ɾ������

void DestroyList(pList list);//��պ���



#endif