#include "LinkList.h"

static Node *BuyNode(ElemType val, Node *next)//������
{
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);

    s->data = val;
    s->next = next;//next == list->next;
    return s;
}

void InitLinkList(pList list)//��ʼ��������
{
    list->count = 0;
    list->head.next = NULL;
}


void InsertElemToList(pList list, ElemType val, int pos)//��������
{
    if (pos<0 || pos>list->count)
    {
        printf("insert pos is error\n");
        return;
    }

    //����1
    /*Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);

    s->data = val;
    Node *p = &list->head;

    while (pos>0)
    {
        p = p->next;
        pos--;
    }
    s->next = p->next;
    p->next = s;*/

    //����2����������½�����ⲿ�����㺯��ʵ�֣�
    Node *p = &list->head ;

    while(pos>0)
    {
    p = p->next ;
    pos--;
    }

    Node *s = BuyNode (val,p->next);
    p->next = s ;

    list->count++;

}

void DeleteElemOfList(pList list, int pos)//ɾ������
{
    if (pos<0 || pos>list->count)
    {
        printf("delete pos is error\n");
        return;
    }

    Node *p = &list->head;

    while (pos>1)
    {
        p = p->next;
        pos--;
    }

    Node *q = p->next;//��¼Ҫɾ���Ľڵ�

    p->next = q->next;
    free(q);//�ͷ�ɾ���Ľ��
    list->count--;
}

void ShowList(pList list)
{
    assert(list != NULL);
    if (list->head.next  == NULL)
    {
        printf("list is empty\n");
        return;
    }

    Node *p = &list->head;//p���൱��ͷ���ĵ�ַ
    //����1:
    //while (p->next != NULL)
    //{
    //    p = p->next;//ֱ��Խ��ͷ��㣬�����ӡͷ���
    //    printf("%d  ", p->data);
    //  
    //}
    //printf("\n");
    //����2��
    p = p->next;//Խ��ͷ��㣬��ֹͷ��㱻��ӡ��ͷ������û�����ݣ�
    while (p)//ֻҪpΪ�վ�˵�������Ѿ�������
    {
        printf("%d ",p->data );
        p = p->next;
    }
    printf("\n ");

}

void Destroylist(pList list)
{
    assert(&list != NULL);

    while(list->count != 0)
    {
        DeleteElemOfList(list, 1);
    }

    if (list->head.next == NULL)
    {
        printf("The link list has been destroyed!\n");
    }
}
