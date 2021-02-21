## Example

    hash_table<int> h;
    int g = 5;
    int k = h.hash(g);
    h.add(k,g);
    cout<<h.exists(k)<<endl;
    g = 15;
    k = h.hash(g);
    h.add(k,g);
    h.traverse();
