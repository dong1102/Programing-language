#ifndef __CYCLINKLIST_H
#define __CYCLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int ElemType;


// ���ṹ
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;


// ��ѭ������ṹ
typedef struct CycLinkList
{
    Node *head;
    int count;
}CycLinkList, *pCyc;

void InitCycList(pCyc list);//��ʼ����ѭ������

void InsertCycList(pCyc list, ElemType val, int pos);//�������ݺ���

void DeleteCycList(pCyc list, int pos);//ɾ�����ݺ���

void ShowList(pCyc list);//��ӡ����

void DestroyList(pCyc list);//��պ���



#endif