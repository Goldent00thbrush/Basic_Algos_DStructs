#include "max_heap.h"
#include <iostream>
using namespace std;
#define MAX 1000

max_heap::max_heap()
{
    heap = new int[MAX]();
    last=0;
}

void max_heap::insert(int key){
    if(is_empty()){ //root
        heap[0]=key;
    }
    else{ //any node
        last += 1;
        heap[last] = key;
        sift_up(heap, last);
    }

}
void max_heap::sift_up(int * heap, int pos){//- needed for insert
    int parent  = (pos-1)/2;
    if (pos>0 & heap[pos]>heap[parent]){
        int temp = heap[pos];
        heap[pos] = heap[parent];
        heap[parent] = temp;
        sift_up(heap, parent);
    }

}
int max_heap::get_max(){// - returns the max item, without removing it
    return heap[0];//root
}
int max_heap::get_size(){// - return number of elements stored
    return last+1;

}
bool max_heap::is_empty(){// - returns true if heap contains no elements
    if(heap[0] == NULL)
        return true;
    return false;
}
 int max_heap::extract_max(int * heap){// - returns the max item, removing it
    int m = heap[0];
    heap[0]= heap[last];
    sift_down(heap, 0);
    last --;
    return m;
 }

 void max_heap::sift_down(int * heap, int pos){// - needed for extract_max
     int leftchild = 2*pos +1, rightchild = 2*pos +2, swap_pos;
     if(heap[leftchild] > heap[rightchild])
         swap_pos = leftchild;
     else
         swap_pos = rightchild;
     if(swap_pos<last ){
         int temp = heap[pos];
         heap[pos]=heap[swap_pos];
         heap[swap_pos] = temp;
         sift_down(heap, swap_pos);
     }

 }
 void max_heap::remove(int i){// - removes item at index x
     heap[i]= heap[last];
     sift_down(heap, i);
     sift_up(heap, i);
     last --;
 }
void max_heap::heapify(int* arr, int size){// - create a heap from an array of elements, needed for heap_sort
    int mid = (size-1)/2 ;
     for (int i=mid; i>=0;i--){
         sift_down(arr, i);
     }
 }
 void max_heap::heap_sort(int* arr, int size){// - take an unsorted array and turn it into a sorted array in-place using a max heap or min heap
    heapify(arr, size);
    for(int i = size - 2; i >= 0; i--) {
        int max = extract_max(arr);
        arr[i] = max;
    }

 }

 void max_heap::print(){
    for(int i=0;i<=last;i++){
        cout<<heap[i]<<endl;
    }
 }
