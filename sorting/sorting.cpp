#include "sorting.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <typename T>
sorting<T>::sorting()
{

}

template <typename T>
void sorting<T>::bubble_sort(T arr[], int sz){
    for (int i=0;i<sz;i++){
        for (int j=0;j<sz-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

template <typename T>
void sorting<T>::insertion_sort(T arr[], int sz){
    // maintain presorted list and insert in it
    for(int i=0;i<sz;i++){
        int j = i;
        while (j>0 && arr[j]<arr[j-1]) {
            int t = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = t;
            j--;
        }
    }
}


template <typename T>
void sorting<T>::merge(T l[], int le, int m, int r){
    int sz1=m-le+1, sz2=r-m, pt1[sz1], pt2[sz2], f=0;
    for(int k=le;k<=m;k++){
        pt1[f]=l[k];
        f++;
    }
    f = 0;
    for(int k=m+1;k<=r;k++){
        pt2[f]=l[k];
        f++;
    }
    int i =0, j=0, c =le;
    while(i<sz1 && j<sz2){
        if(pt1[i] <pt2[j]){
            l[c] = pt1[i];
            i++;
        }
        else if(pt1[i] >pt2[j]){
            l[c] = pt2[j];
            j++;
        }
        c++;
    }
    while(i<sz1){
        l[c]=pt1[i];
        i++;
        c++;
    }
    while(j<sz2){
        l[c]=pt2[j];
        j++;
        c++;
    }
}

template <typename T>
void sorting<T>::merge_sort(T arr[], int l, int r){
    if(l>=r)
        return;
    int m = l+ (r-l)/2;
    merge_sort(arr,l , m);
    merge_sort(arr,m+1 , r);
    merge(arr,l,m,r);
}
template <typename T>
int sorting<T>::partion(T l[], int le, int r){

    int sz = r-le, pivot = l[r]; // pivot
    int i = (le - 1);
    for (int j = le; j <= r - 1; j++)
    {
        // If current element is smaller than the pivot
        if (l[j] < pivot)
        {
            i++; // increment index of smaller element
            T  temp = l[i];
            l[i] = l[j];
            l[j]= temp;
        }
    }
        T  temp = l[i+1];
        l[i+1] = l[r];
        l[r]= temp;
        return (i + 1);
}

template <typename T>
void sorting<T>::quick_sort(T arr[],int l, int r){
//    if (sz<2)
//        return;
//    int pivot = rand()%sz-1,l=0, r=sz-1;
//    while(l<r){
//        while(arr[l]<arr[pivot]){
//            l++;
//        }
//        while(arr[r]>arr[pivot]){
//            r--;
//        }
//        if(l<=r){
//        T temp = arr[l];
//        arr[l]=arr[r];
//        arr[r] = temp;
//        }
//    }

//    quick_sort(arr,l);
//    quick_sort(&arr[l+1], sz-l-1);
    if (l < r)
        {
            int pi = partion(arr, l, r);

            // Separately sort elements before
            // partition and after partition
            quick_sort(arr, l, pi - 1);
            quick_sort(arr, pi + 1, r);
        }
}

template <typename T>
void sorting<T>::selection_sort(T arr[],int sz){
    int id = 0, sm, sm_id, temp;
    while(id<sz){
        sm = arr[id];
        sm_id=id;
        for (int i=id;i<sz;i++){
            if(arr[i]<sm){
                sm = arr[i];
                sm_id = i;
            }
        }
        temp = arr[id];
        arr[id] = arr[sm_id];
        arr[sm_id]= temp;
        id++;
    }

}

template <typename T>
void sorting<T>::radix_sort(T arr[],int n){
    int maximum = arr[0];
    for(int i=1;i<n;i++){
        maximum = max(maximum, arr[i]);
    }

    int digits = 0;

    while(maximum > 0){
        digits++;
        maximum /= 10;
    }
    for(int i=0;i<digits;i++){
        int power = pow(10, i), new_array[n], count[10]={0};

        for(int j=0;j<n;j++){
            int num = (arr[j]/power) % 10;
            count[num]++;
        }
        for(int j=1;j<10;j++){
            count[j] += count[j-1];
        }

        for(int j=n-1;j>=0;j--){
            int num = (arr[j]/power) % 10;
            new_array[count[num]-1] = arr[j];
            count[num]--;
        }

        // Updating the original array using New Array
        for(int j=0;j<n;j++)
            arr[j] = new_array[j];

    }


}
