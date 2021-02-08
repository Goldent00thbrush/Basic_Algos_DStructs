#include "node.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<typename t>
class linked_list
{
private:
    Node<t> * head, * curr;
    int s;

public:
    linked_list();
    int size(); // returns number of data elements in list
     bool empty(); // - bool returns true if empty
     t value_at(int index);// - returns the value of the nth item (starting at 0 for first)
     void push_front(t value);// - adds an item to the front of the list
     t pop_front();// - remove front item and return its value
     void push_back(t value);// - adds an item at the end
     t pop_back();// - removes end item and returns its value
     t front(); //- get value of front item
     t back();// - get value of end item
     void insert(int index, t value);// - insert value at index, so current item at that index is pointed to by new item at index
     void erase(int index);// - removes node at given index
     t value_n_from_end(int n); //- returns the value of the node at nth position from the end of the list
     void reverse();// - reverses the list
     void remove_value(t value); // removes the first item in the list with this value
};

#endif // LINKED_LIST_H
