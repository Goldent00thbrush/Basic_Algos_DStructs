#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "node.h"

template<typename T>
class binary_search_tree
{
private:
    node<T> * root;
    int s;
    void delete_tree(node<T>* root);
    node<T>* is_in_tree(T val, node<T>* root); // returns true if given value exists in the tree
    int get_height(node<T>* root); // returns the height in nodes (single node's height is 1)
    node<T>* get_parent(T val, node<T>* curr);
    void print_values(node<T>*); // prints the values in the tree, from min to max
public:
    binary_search_tree();
    void insert(T d); // insert value into tree
     int get_node_count(); // get count of values stored
     void print_values(); // prints the values in the tree, from min to max
     void delete_tree();
     bool is_in_tree(T val); // returns true if given value exists in the tree
     int get_height(); // returns the height in nodes (single node's height is 1)
     T get_min(); // returns the minimum value stored in the tree
     T get_max(); // returns the maximum value stored in the tree
     bool is_binary_search_tree(node<T> * root);
     void delete_value(T d);
     T get_successor(T val); // returns next-highest value in tree after given value, -1 if none
     node<T> * get_root();
};

#endif // BINARY_SEARCH_TREE_H
