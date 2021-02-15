#ifndef QUEUE_L_H
#define QUEUE_L_H
#include "node.h"

template<typename T>
class queue_l
{
private:
    Node<T> * tail, * prev;
    int s;
public:
    queue_l();
    void enqueue(T value);// - adds value at position at tail
    T dequeue();// - returns value and removes least recently added element (front)
    bool empty();
};

#endif // QUEUE_L_H
