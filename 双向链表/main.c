#include "DoubleList.h"

int main()
{
    DoubleList list;

    InitDoubleList(&list);

    for (int i = 0; i < 5; ++i)
    {
        InsertDoubleList(&list, i * 10, i);
    }

    ShowDoubleList(&list);

    DeleteDoubleList(&list, 3);
    ShowDoubleList(&list);

    ReverseShow(&list);

    DestroyList(&list);
}