#include "stackt.h"
#include <iostream>

template<typename T>
stackt<T>::stackt()
{
    s = new T[MAX];
    c = 0;
}

template<typename T>
bool stackt<T>::is_empty(){
    if (c==0)
        return true;
    return false;
}

template<typename T>
T stackt<T>::pop(){
    c -=1;
    if(c<0)
        return NULL;
    return s[c];
}

template<typename T>
void stackt<T>::push(T val){
    s[c] = val;
    c +=1;
}

template<typename T>
int stackt<T>::size(){
    return c;
}

template<typename T>
T stackt<T>::top(){
    return s[c];
}
