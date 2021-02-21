#include "hash_table.h"
#include <iostream>
using namespace std;
template<typename T>
hash_table<T>::hash_table()
{
    s=MAX;
    arr = new T[MAX]();
}


template<typename T>
int hash_table<T>::hash(T k){ // - m is size of hash table
    return k % s;
}
template<typename T>
void hash_table<T>::add(int key, T value){// - if key already exists, update value
    if (!exists(key)){
        arr[key]= value;
    }
    else{
        add(key+1, value); //needs to be a breaking condition
    }
}
template<typename T>
bool hash_table<T>::exists(int key){
    if (arr[key] == NULL)
        return false;
    return true;
}
template<typename T>
T hash_table<T>::get(int key){
    return arr[key];
}
template<typename T>
void hash_table<T>::remove(int key){
    arr[key] = NULL;
}

template<typename T>
void hash_table<T>::traverse(){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<endl;
    }
}
