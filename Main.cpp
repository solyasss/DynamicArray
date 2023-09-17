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

    DynamicArray result = a + 5;
    result.output();
    result = a - 1;
    result.output();
    result = a * 5;
    result.output();
    result = a - b;
    result.output();
    result = a + b;
    result.output();
    ++result;
    result.output();
    --result;
    result.output();

    system("pause");
}