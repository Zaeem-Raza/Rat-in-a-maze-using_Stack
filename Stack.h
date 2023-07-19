#pragma once
#include <iostream>
#include <stdlib.h>
#include <iostream>
using namespace std;
template <class T>
class Stack
{
    T *data;
    int capacity;
    int top;
    void reSize(int newCapacity);

public:
    Stack();
    Stack(const Stack<T> &obj);
    Stack &operator=(const Stack<T> &obj);
    ~Stack();
    T stackTop() const;
    bool isFull() const;
    bool isEmpty() const;
    int getCapacity() const;
    int getNumberOfElements() const;
    void push(T element);
    void print() const;
    T pop();
};
