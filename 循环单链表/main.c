#include "CycLinkList.h"

int main()
{
    CycLinkList  list;

    InitCycList(&list);//��������

    for (int i = 0; i < 5; ++i)
    {
        InsertCycList(&list, i * 10, i);
    }

    ShowList(&list); 

    DestroyList(&list);

    //while (list.head != NULL)//�൱���������
    //{
    //    DeleteCycList(&list, 1);
    //}
    //ShowList(&list);


    
    //DeleteCycList(&list, 4);//ɾ������
    //ShowList(&list);
    //
    //DeleteCycList(&list, 1);
    //ShowList(&list);
    //DeleteCycList(&list, 1);
    //ShowList(&list);
    //DeleteCycList(&list, 1);
    //ShowList(&list);  //  10 20 30 40
}