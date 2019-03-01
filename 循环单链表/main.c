#include "CycLinkList.h"

int main()
{
    CycLinkList  list;

    InitCycList(&list);//插入数据

    for (int i = 0; i < 5; ++i)
    {
        InsertCycList(&list, i * 10, i);
    }

    ShowList(&list); 

    DestroyList(&list);

    //while (list.head != NULL)//相当于清空链表
    //{
    //    DeleteCycList(&list, 1);
    //}
    //ShowList(&list);


    
    //DeleteCycList(&list, 4);//删除数据
    //ShowList(&list);
    //
    //DeleteCycList(&list, 1);
    //ShowList(&list);
    //DeleteCycList(&list, 1);
    //ShowList(&list);
    //DeleteCycList(&list, 1);
    //ShowList(&list);  //  10 20 30 40
}