#include "dynamic_array.h"
#include <iostream>
using namespace std;

template <typename T>
dynamic_array<T>::dynamic_array()
{
    s = 0;
    c = 2;
    arr = new T[c];
}
template <typename T>
void dynamic_array<T>::resize(int new_capacity){ // private function -- double
    c = new_capacity;
    T * t_arr = new T[c];
    for (int i=0;i<s;i++){
        *(t_arr+i)=*(arr+i);
    }
//    copy(arr, t_arr); //could do for loop
    arr= t_arr;
    delete[] t_arr;
}
template <typename T>
int dynamic_array<T>::size(){//  number of items
    return s;
}

template <typename T>
int dynamic_array<T>::capacity(){// number of items it can hold
    return c;
}
template <typename T>
bool dynamic_array<T>::is_empty(){
    return (s==0);
}
template <typename T>
T dynamic_array<T>::at(int index){ // returns item at given index, blows up if index out of bounds
    return *(arr+index);
}
template <typename T>
void dynamic_array<T>::push(T item){
   insert(s,item);
}
template <typename T>
void dynamic_array<T>::insert(int index, T item){//inserts item at index, shifts that index's value and trailing elements to the right
    if (s>=c)
        resize(c*2);
    s ++;
    T t= *(arr+s-1);
    for (int i=s;i>=index+1;i--){
        *(arr+i) = t ;
        t= *(arr+i-2);
    }
    *(arr+index) = item;
}
template <typename T>
void dynamic_array<T>::prepend(T item){// can use insert above at index 0
    insert(0,item);
}
template <typename T>
T dynamic_array<T>::pop(){// remove from end, return value -- if size is 1/4 of capacity, resize to half
  return del(s-1);
}
template <typename T>
T dynamic_array<T>::del(int index){// delete item at index, shifting all trailing elements left
    T r = *(arr+ index), t=*(arr+ index+1);
    for (int i=index;i<s;i++){
//        t = *(arr+i-1);
//        *(arr+i-1) = *(arr+i);
//        *(arr+i) = t;
        *(arr+i) = t;
        cout<<t<<endl;
        t= *(arr+i+2);
    }
    if(s<=(c/4))
        resize(c/2);
    s--;
    return r;
}
template <typename T>
void dynamic_array<T>::remove(T item){// looks for value and removes index holding it (even if in multiple places)
  for (int i=0; i<s;i++){
      if (*(arr+i) == item)
          del(i);
  }
}
template <typename T>
int dynamic_array<T>::find(T item){// looks for value and returns first index with that value, -1 if not found
    for (int i=0; i<s;i++){
        if (*(arr+i) == item)
            return i;
    }
    return  -1;
}
template <typename T>
dynamic_array<T>::~dynamic_array(){
    delete[] arr;
}
