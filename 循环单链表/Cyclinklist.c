#include "CycLinkList.h"

void InitCycList(pCyc list)
{
    assert(list != NULL);

    list->count = 0;
    list->head = NULL;
}

static Node *BuyNode(ElemType val, Node *next)//�½�������
{
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);

    s->data = val;
    if (next != NULL)//����������к�̣���˵������Ĳ��ǵ�һ�����
    {
        s->next = next;
    }
    else//����������޺�̣���˵��������ǵ�һ�����
    {
        s->next = s;
    }

    return s;
}

void InsertCycList(pCyc list, ElemType val, int pos)
{
    // ��������һ������ʱ�����
    if (list->head == NULL)
    {
        list->head = BuyNode(val, NULL);
        list->count++;
        return;
    }

    if (pos < 0 || pos > list->count)
    {
        printf("insert pos is error\n");
        return;
    }

    Node *p = list->head;
    // ���posΪ0���൱����countλ�ú����������
    int pos2 = pos != 0 ? pos : list->count;

    while (pos2 > 1)
    {
        p = p->next;
        pos2--;
    }

    //����һ
    // 	Node *s = (Node *)malloc(sizeof(Node));
    // 	assert(s != NULL);
    // 
    // 	s->data = val;
    // 	s->next = p->next;

    //������
    Node *s = BuyNode(val, p->next);
    p->next = s;

    // ���posΪ0���������ͷָ���ָ���²���Ľ��
    if (pos == 0)
    {
        list->head = s;
    }

    list->count++;
}

void DeleteCycList(pCyc list, int pos)
{
    assert(list != NULL && list->head != NULL);

    if (list->head->next == list->head)
    {
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    if (pos < 1 || pos > list->count)
    {
        printf("delete pos is error\n");
        return;
    }

    Node *p = list->head;

    if (pos == 1)
    {
        while (p->next != list->head)
        {
            p = p->next;
        }

        list->head = list->head->next;
    }
    else
    {
        while (pos > 2)
        {
            p = p->next;
            pos--;
        }
    }

    Node *q = p->next;
    p->next = q->next;

    free(q);
    list->count--;
}

void ShowList(pCyc list)
{
    assert(list != NULL);
    if (list->head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    Node *p = list->head;

    while (p->next != list->head)
    {
        printf("%d  ", p->data);
        p = p->next;
    }

    printf("%d  \n", p->data);
}

void DestroyList(pCyc list)
{
    assert(list != NULL);

    while (list->count != 0)
    {
        DeleteCycList(list, 1);
    }

    if (list->head == NULL)
    {
        printf("Doublelist is empty!\n");
    }

}