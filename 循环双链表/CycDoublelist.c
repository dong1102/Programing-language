#include "CycDoublelist.h"

void InitCycDouList(pCycList list)
{
    assert(list != NULL);
    list->head = NULL;
    list->count = 0;
}

static CycNode *BuyNode(ElemType value, CycNode *prev, CycNode* next)
{
    CycNode * s = (CycNode *)malloc(sizeof(CycNode));
    assert(s != NULL);

    s->data = value;

    if (prev == NULL || next == NULL)
    {
        s->next = s->prev = s;
    }
    else
    {
        s->next = next;
        s->prev = prev;
    }

    return s;
}

static void Insert(ElemType value, pCycList list, CycNode* p)
{
    CycNode *s = BuyNode(value, p, p->next);

    p->next->prev = s;
    p->next = s;

    list->count++;
}

void InsertCycDouList(pCycList list, ElemType value, int pos)
{
    assert(list != NULL);

    if (list->head == NULL)//插入第一个结点
    {
        CycNode *s = BuyNode(value, NULL, NULL);
        list->head = s;
        list->count++;
        return;
    }

    if (pos < 0 || pos > list->count)
    {
        printf("insert pos is error\n");
        return;
    }

    CycNode *p = list->head;

    if (pos == 0)//第一个位置插入
    {
        p = p->prev;
        Insert(value, list, p);
        list->head = list->head->prev;
    }
    else//正常插入
    {
        while (pos > 1)
        {
            p = p->next;
            pos--;
        }

        Insert(value, list, p);
    }
}