#include "Stack.h"
template <class T>
inline Stack<T>::Stack()
{
    capacity = 2;
    top = -1;
    data = new T[capacity];
}

template <class T>
Stack<T>::Stack(const Stack<T> &obj)
{
    // copy constructor
    delete[] data;
    capacity = obj.capacity;
    data = new T[capacity];
    for (int i = 0; i < obj.getNumberOfElements(); i++)
    {
        data[i] = obj.data[i];
    }
    top = obj.top;
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &obj)
{
    if (this != &obj)
    {
        capacity = obj.capacity;
        data = new T[capacity];
        for (int i = 0; i <= obj.top; i++)
        {
            // data.push(obj.data[i]);
            data[i] = obj.data[i];
        }
        top = obj.top;
    }
    return *this;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <class T>
T Stack<T>::stackTop() const
{
    return data[top];
}

template <class T>
bool Stack<T>::isFull() const
{
    return (top + 1 == capacity);
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return (top == -1);
}

template <class T>
int Stack<T>::getCapacity() const
{
    return this->capacity;
}

template <class T>
int Stack<T>::getNumberOfElements() const
{
    return top + 1;
}

template <class T>
void Stack<T>::push(T element)
{
    if (isFull())
    {
        reSize(capacity + 5);
    }
    data[++top] = element;
}

template <class T>
void Stack<T>::print() const
{
    for (int i = top; i >= 0; i--)
    {
        cout << data[i] << " ";
    }
    cout << "\n";
}

template <class T>
T Stack<T>::pop()
{
    if (!isEmpty())
        return data[top--];
    cout << "Stack is Empty" << endl;
}

template <class T>
void Stack<T>::reSize(int newcapacity)
{

    T *temp = new T[newcapacity];
    for (int i = 0; i <= top; i++)
    {
        temp[i] = this->data[i];
    }
    delete[] data;
    data = temp;
    capacity = newcapacity;
}