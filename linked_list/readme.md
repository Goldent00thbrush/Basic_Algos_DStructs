## Example 
    
    linked_list<int> l;
    l.push_front(2);
    l.push_front(3);
    cout<<l.value_at(0)<<endl;
    cout<<l.value_at(1)<<endl;
    cout<<l.value_at(5)<<endl;
    l.pop_front();
    l.pop_front();
    cout<<l.value_at(0)<<endl;
    l.push_back(2);
    l.push_back(3);
    l.pop_back();
    l.pop_back();
    cout<<l.back()<<endl;
    cout<<"print"<<endl;
    l.push_back(1);
    l.push_back(2);
    l.push_back(4);
    l.insert(2,3);
    l.reverse();
    l.erase(0);
    for (int i=0;i<5;i++)
        cout<<l.value_at(i)<<endl;
    cout<<l.value_n_from_end(2)<<endl;
    l.remove_value(4);
    cout<<"print"<<endl;
    for (int i=0;i<5;i++)
        cout<<l.value_at(i)<<endl;
