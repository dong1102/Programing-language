#include "LinkList.h"

int main()
{
    LinkList list; //  struct Node head   int count
    InitLinkList(&list);

    for (int i = 0; i<7; i++)
    {
        InsertElemToList(&list, i*10, i);//插入数据
    }
    //InsertElemToList(&list,1,0);

    ShowList( &list); 
    
    DeleteElemOfList(&list, 1);//删除数据
    ShowList(&list);

    Destroylist(&list);//销毁链表
    
    
   
   
    
}