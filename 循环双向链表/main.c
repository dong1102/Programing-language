#include "CycDoublelist.h"

int main()
{
    CycDouList list;

    for (int i = 0; i < 5; i++)
    { 
        InsertCycDouList(&list, i * 10, i);

    }
   
}