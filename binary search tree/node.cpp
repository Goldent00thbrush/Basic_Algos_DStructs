#include "node.h"
#include <iostream>

template<typename T>
node<T>::node()
{
    right = nullptr;
    left = nullptr;
    data = NULL;
}

template<typename T>
node<T>::node(T d)
{
    right = nullptr;
    left = nullptr;
    data = d;
}

