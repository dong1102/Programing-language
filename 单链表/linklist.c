#include "LinkList.h"

static Node *BuyNode(ElemType val, Node *next)//购买结点
{
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);

    s->data = val;
    s->next = next;//next == list->next;
    return s;
}

void InitLinkList(pList list)//初始化单链表
{
    list->count = 0;
    list->head.next = NULL;
}


void InsertElemToList(pList list, ElemType val, int pos)//插入数据
{
    if (pos<0 || pos>list->count)
    {
        printf("insert pos is error\n");
        return;
    }

    //方法1
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

    //方法2（将构造的新结点在外部购买结点函数实现）
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

void DeleteElemOfList(pList list, int pos)//删除数据
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

    Node *q = p->next;//记录要删除的节点

    p->next = q->next;
    free(q);//释放删除的结点
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

    Node *p = &list->head;//p就相当于头结点的地址
    //方法1:
    //while (p->next != NULL)
    //{
    //    p = p->next;//直接越过头结点，避免打印头结点
    //    printf("%d  ", p->data);
    //  
    //}
    //printf("\n");
    //方法2：
    p = p->next;//越过头结点，防止头结点被打印（头结点里边没有数据）
    while (p)//只要p为空就说明链表已经遍历完
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
