#pragma once
#include "DynamicArray.h"

DynamicArray get_obj()
{
    DynamicArray obj(3);
    obj.input();

    return obj;
}
void main()
{
    DynamicArray a(10);
    DynamicArray b(15);
    a.input();
    a.output();

    DynamicArray res = a + 5;
    res.output();
    res = a - 1;
    res.output();
    res = a * 5;
    res.output();
    res = a - b;
    res.output();
    res = a + b;
    res.output();
    ++res;
    res.output();
    --res;
    res.output();

    system("pause");
}