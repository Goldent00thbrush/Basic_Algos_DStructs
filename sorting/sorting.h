#ifndef SORTING_H
#define SORTING_H

template <typename T>
class sorting
{
private:
    void merge(T l[], int le, int m, int r);
    int partion(T l[], int le, int r);
public:
    sorting();
    void bubble_sort(T arr[], int sz);
    void insertion_sort(T arr[], int sz);
    void merge_sort(T arr[], int l, int r);
    void quick_sort(T arr[],int l, int r);
    void selection_sort(T arr[], int sz);
    void radix_sort(T arr[], int sz);
};

#endif // SORTING_H
