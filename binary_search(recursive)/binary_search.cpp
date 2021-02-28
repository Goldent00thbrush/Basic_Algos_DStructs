bool binary_search(int a[] , int val, int st, int e){
    int s = (e-st)/2 + st;
    if(s==0 || s>e)
        return false;
    int k = a[s];
    if(k==val)
        return true;
    if(k>val)
        return binary_search(a,val,st,s);
    return binary_search(a,val, s+1, e);
}

template<typename T>
bool binary_search_t(T a[] , T val, int st, int e){
    int s = (e-st)/2 + st;
    if(s==0 || s>e)
        return false;
    int k = a[s];
    if(k==val)
        return true;
    if(k>val)
        return binary_search(a,val,st,s);
    return binary_search(a,val, s+1, e);
}
