#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class dynamic_array
{
private:
    int s,c;
    T* arr;
    void resize(int new_capacity); // private function -- double
public:
    dynamic_array();
    int size();//  number of items
    int capacity();// number of items it can hold
    bool is_empty();
    T at(int index); // returns item at given index, blows up if index out of bounds
    void push(T item);
    void insert(int index, T item);//inserts item at index, shifts that index's value and trailing elements to the right
    void prepend(T item);// can use insert above at index 0
    T pop();// remove from end, return value -- if size is 1/4 of capacity, resize to half
    T del(int index);// delete item at index, shifting all trailing elements left
    void remove(T item);// looks for value and removes index holding it (even if in multiple places)
    int find(T item); // looks for value and returns first index with that value, -1 if not found
    ~dynamic_array();

};

#endif // DYNAMIC_ARRAY_H
