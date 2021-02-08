#include "linked_list.h"
#include "node.cpp"
#include <iostream>
using namespace std;

template <typename t>
linked_list<t>::linked_list()
{
    head = nullptr;
    curr = nullptr;
    s=0;
}

template <typename t>
int linked_list<t>::size(){ // returns number of data elements in list
    return s;
}
template <typename t>
bool linked_list<t>::empty(){ // - bool returns true if empty
    if(s==0)
        return true;
    else
        return false;
}
 template <typename t>
 t linked_list<t>::value_at(int index){// - returns the value of the nth item (starting at 0 for first)
     if(s==0 || s<=index)
         return NULL;
     curr=head;
     for(int i=0;i<index; i++){
         if(curr!=nullptr)
             curr= curr->next;
         }
     return curr->value;
 }
 template <typename t>
 void linked_list<t>::push_front(t value){// - adds an item to the front of the list
    if(s==0){
        head= new Node<t>();
    }
    else{
    curr= head;
    head= new Node<t>();
    head->next = curr;
    }
    head->value=value;
    s +=1;

    curr=head;
//    while(curr!=nullptr){
//        cout<<curr->value<<endl;
//        curr= curr->next;
//    }
 }
 template <typename t>
 t linked_list<t>::pop_front(){// - remove front item and return its value
  if(s==0){
      return NULL;
  }
  t v = head->value;
  head = head->next;
  s-=1;
  return v;
 }
 template <typename t>
 void linked_list<t>::push_back(t value){// - adds an item at the end
     curr=head;
     if(s==0){
         head=new Node<t>();
         head ->value=value;
         s+=1;
         return;
     }
     for (int i=0;i<s-1;i++){
      curr=curr->next;
  }
     curr->next=new Node<t>();
     curr= curr->next;
     curr ->value=value;
     s+=1;
 }
 template <typename t>
 t linked_list<t>::pop_back(){// - removes end item and returns its value
  if(s==0){
      return NULL;
  }
  curr=head;
  for (int i=0;i<s-1;i++){
   curr=curr->next;
}
  t v= curr->value;
  curr=nullptr;
  s -=1;
  return v;
 }
 template <typename t>
 t linked_list<t>::front(){ //- get value of front item
     if(s==0)
         return NULL;
     return head->value;
 }
 template <typename t>
 t linked_list<t>::back(){// - get value of end item
     if(s==0)
         return NULL;
     curr=head;
     for (int i=0;i<s-1;i++){
      curr=curr->next;
   }
     return curr->value;
 }
template <typename t>
void linked_list<t>::insert(int index, t value){// - insert value at index, so current item at that index is pointed to by new item at index
    curr=head;
    for (int i=0;i<index-1;i++){
     curr=curr->next;
  }
    Node<t> * n= new Node<t>();
    n->value=value;
    n->next=curr->next;
    curr->next=n;
    s += 1;
}
 template <typename t>
 void linked_list<t>::erase(int index){// - removes node at given index
     curr=head;
     Node<t>* prev=head;
     if(index==0){
         head=head->next;
        return;
     }
     for (int i=0;i<index-2;i++){
      prev=curr;
      curr=curr->next;
   }
    prev->next=curr->next;
 }
template <typename t>
t linked_list<t>::value_n_from_end(int n){ //- returns the value of the node at nth position from the end of the list
    if(s==0)
        return NULL;
    curr=head;
    for(int i=0;i<s-n; i++){
        if(curr!=nullptr)
            curr= curr->next;
        }
    return curr->value;
}
 template <typename t>
 void linked_list<t>::reverse(){// - reverses the list
  linked_list<t> * n;
  curr=head;
  for (int i=0;i<s;i++){
     n->push_front(curr->value);
     curr=curr->next;
  }
  head=n->head;
 }
 template <typename t>
 void linked_list<t>::remove_value(t value){ // removes the first
  curr=head;
  int i=0;
  while(curr->value!=value && curr!=nullptr){
      curr= curr->next;
      i +=1;
  }
  erase(i);
 }
