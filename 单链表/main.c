#include "LinkList.h"

int main()
{
    LinkList list; //  struct Node head   int count
    InitLinkList(&list);

    for (int i = 0; i<7; i++)
    {
        InsertElemToList(&list, i*10, i);//��������
    }
    //InsertElemToList(&list,1,0);

    ShowList( &list); 
    
    DeleteElemOfList(&list, 1);//ɾ������
    ShowList(&list);

    Destroylist(&list);//��������
    
    
   
   
    
}