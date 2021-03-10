# Example

    binary_search_tree<int> b;
    b.insert(50);
    b.insert(30);
    b.insert(20);
    b.insert(40);
    b.insert(70);
    b.insert(60);
    b.insert(80);
    b.print_values();
    cout<<b.get_node_count()<<endl;
    cout<<b.get_max()<<endl;
    cout<<b.get_min()<<endl;
    cout<<b.is_in_tree(40)<<endl;
    cout<<b.is_in_tree(100)<<endl;
    cout<<b.get_height()<<endl;
    cout<<b.get_successor(20)<<endl;
    cout<<b.get_successor(30)<<endl;
    cout<<b.get_successor(80)<<endl;
    cout<<b.is_binary_search_tree(b.get_root())<<endl;
    b.delete_value(80);
    b.delete_value(70);
    b.delete_value(30);
    b.print_values();
    b.delete_tree();
    b.print_values();
   
