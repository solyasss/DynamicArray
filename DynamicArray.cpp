#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray() : ptr(nullptr), size(0) {}

DynamicArray::DynamicArray(int s)
{
    cout << "Construct by 1 param\n";
    size = s;
    ptr = new int[s]{0};
}

DynamicArray::DynamicArray(const DynamicArray &a)
{
    cout << "Copy construct\n";
    size = a.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[i];
    }
}

DynamicArray::~DynamicArray()
{
    cout << "Destruct\n";
    delete[] ptr;
}

void DynamicArray::input()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 20;
    }
}

void DynamicArray::output() const
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
}

int *DynamicArray::get_pointer() const
{
    return ptr;
}

int DynamicArray::get_size() const
{
    return size;
}

void DynamicArray::resize(int new_size)
{
    if (this->size == new_size)
    {
        cout << "Array have the same size." << endl;
    }
    else
    {
        int *new_ptr = new int[new_size];

        for (int i = 0; i < this->size; i++)
        {
            new_ptr[i] = ptr[i];
        }

        for (int i = this->size; i < new_size; i++)
        {
            new_ptr[i] = 0;
        }

        delete[] ptr;
        ptr = new_ptr;
        this->size = new_size;
    }
}

void DynamicArray::sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

int DynamicArray::search(int value) const
{
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void DynamicArray::reverse()
{
    int left = 0;
    int right = this->size - 1;
    int temp;

    while (left < right)
    {
        temp = ptr[left];
        ptr[left] = ptr[right];
        ptr[right] = temp;

        left++;
        right--;
    }
}

DynamicArray DynamicArray::operator+(int value)
{
    int new_size = size + value;
    DynamicArray new_array(new_size);

    for (int i = 0; i < size; i++)
    {
        new_array.ptr[i] = this->ptr[i];
    }

    for (int i = size; i < new_size; i++)
    {
        new_array.ptr[i] = 0;
    }

    new_array.size = new_size;
    return new_array;
}

DynamicArray DynamicArray::operator-(int value)
{
    if (size < value)
    {
        int new_size = size - value;

        DynamicArray new_array(new_size);

        for (int i = 0; i < new_size; i++)
        {
            new_array.ptr[i] = ptr[i];
        }

        return new_array;
    }
    else
    {
        return *this;
    }
}

DynamicArray DynamicArray::operator*(int value)
{
    DynamicArray new_array;
    new_array.size = size;
    new_array.ptr = new int[new_array.size];

    for (int i = 0; i < size; i++)
    {
        new_array.ptr[i] = ptr[i];
    }

    for (int i = 0; i < new_array.size; i++)
    {
        new_array.ptr[i] *= value;
    }
    return new_array;
}
