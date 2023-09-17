#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
    int *ptr;
    int size;

public:
    DynamicArray();
    DynamicArray(int);
    DynamicArray(const DynamicArray &);
    ~DynamicArray();
    void input();
    void output() const;
    int *get_pointer() const;
    int get_size() const;

    void resize(int size);
    void sort();
    int search(int a) const;
    void reverse();

    DynamicArray operator+(int b);
    DynamicArray operator-(int b);
    DynamicArray operator*(int b);

    DynamicArray operator-(DynamicArray b);
    DynamicArray operator+(DynamicArray b);

    DynamicArray operator++();
    DynamicArray operator--();
};
