#ifndef MAX_HEAP_H
#define MAX_HEAP_H

class max_heap
{
private:
    int * heap;
    int last;
    void sift_up(int* heap, int pos);//- needed for insert
    void sift_down(int * heap, int pos);// - needed for extract_max
    void heapify(int *, int);// - create a heap from an array of elements, needed for heap_sort
    int extract_max(int *);// - returns the max item, removing it
public:
    max_heap();
    void insert(int key);
    int get_max();// - returns the max item, without removing it
    int get_size();// - return number of elements stored
    bool is_empty();// - returns true if heap contains no elements
     void remove(int i);// - removes item at index x
     void heap_sort(int* arr, int );// - take an unsorted array and turn it into a sorted array in-place using a max heap or min heap
     void print();
};

#endif // MAX_HEAP_H
