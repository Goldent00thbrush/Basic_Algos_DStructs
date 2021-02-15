#include "queue_t.h"
#include <iostream>

template <typename T>
queue_t<T>::queue_t()
{
    q = new T[MAX];
    s = 0;
}


template <typename T>
bool queue_t<T>::enqueue(T value){// adds item at end of available storage
 if (! is_full()){
 q[s] = value;
 s += 1;
 return true;
 }
 return false;
}
template <typename T>
T queue_t<T>::dequeue(){//returns value and removes least recently added element
 if (! is_empty()){
     s -=1;
     return q[s];
 }
 return  NULL;
}
template <typename T>
bool queue_t<T>::is_empty(){
    if (s==0){
        return true;
    }
    return false;
}
template <typename T>
bool queue_t<T>::is_full(){
    if(s==MAX){
        return true;
    }
    return false;
}
