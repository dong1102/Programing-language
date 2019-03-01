#ifndef __LINKLIST_H
#define __LINKLIST_H


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

//������ṹ

typedef int ElemType;

//�������

typedef struct Node
{
    ElemType  data;
    struct Node *next;
}Node;

//��ͷ���

typedef struct LinkList
{
    struct Node head;
    int count;
}LinkList, *pList;

void InitLinkList(pList list);//��ʼ��������

void InsertElemToList(pList list, ElemType val, int pos);//�������ݺ���

void DeleteElemOfList(pList list, int pos);//ɾ�����ݺ���

void Destroylist(pList list);//���ٺ���

void ShowList(pList list);//��ӡ����

#endif

