#include "queue_l.h"
#include "node.cpp"
#include <iostream>

template<typename T>
queue_l<T>::queue_l()
{
    tail = nullptr;
    prev = nullptr;
    s = 0;
}

template<typename T>
void queue_l<T>::enqueue(T value){// - adds value at position at tail
   if(empty()){
       tail = new Node<T>();
       tail->prev = nullptr;
   }
   else{
       Node<T> * prev = tail;
       tail->next= new Node<T>();
       tail = tail -> next;
       tail -> prev = prev;
   }
   tail->value= value;
   s += 1;
}

template<typename T>
T queue_l<T>::dequeue(){// - returns value and removes least recently added element (front)
    if (empty())
        return  NULL;
    T v = tail -> value;
    tail = tail -> prev;
    s -= 1;
    return v;
}

template<typename T>
bool queue_l<T>::empty(){
    if (s==0){
        return true;
    }
    return false;
}
