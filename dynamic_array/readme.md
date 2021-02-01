## Example 

    dynamic_array<int> d;
    for (int i=1; i<=5;i++){
        d.push(i);
        cout<<i<<endl;
    }
    cout << "Size " <<d.size()<< endl;
    cout << "Capacity " <<d.capacity()<< endl;
    cout << "Is empty " <<d.is_empty()<< endl;
    d.insert(5, 45);
    d.prepend(100);
    d.pop();
    d.del(6);
    d.remove(100);
    cout<<"15 is at "<<d.find(15)<<endl;
    cout<<"Contents of array"<<endl;
    for (int i=0; i<7;i++){
        cout<<d.at(i);
    }
