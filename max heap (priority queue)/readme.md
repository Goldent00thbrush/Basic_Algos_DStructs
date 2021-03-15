## Example

    max_heap h;
    int l [] = {35,33, 42, 10, 14, 19, 27, 44, 26, 31};
    h.is_empty();
    for (int i=0; i<10;i++){
        h.insert(l[i]);
    }
    h.print();
    cout<<h.get_max()<<endl;
    cout<<h.get_size()<<endl;
    h.remove(0);
    h.print();
    h.heap_sort(l, 10);
    for (int i=0; i<10;i++){
        cout<<l[i]<<endl;
    }
    
  Reference the example https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm
