#include "binary_search_tree.h"
#include "node.cpp"
#include <iostream>
using namespace std;

template<typename T>
binary_search_tree<T>::binary_search_tree()
{
    root = nullptr;
    s = 0;
}

template<typename T>
void binary_search_tree<T>::insert(T d){ // insert value into tree
    s ++;
    if (root == nullptr){
        root = new node<T>(d);
    }
    else{
    node<T>* curr = root, *prev=root;
    int flag = 0;
    while(true){
        if(curr == nullptr){
            curr = new node<T>(d);
            if (flag == 1)
                prev ->left = curr;
            else if(flag ==2)
                prev -> right = curr;
            break;
        }
        else if(curr->data> d){
               prev = curr;
               curr = curr->left;
               flag = 1;
        }
        else if(curr->data<d){
            prev = curr;
            curr = curr->right;
            flag = 2;
        }

    }
    }
}
template<typename T>
int binary_search_tree<T>::get_node_count(){ // get count of values stored
    return s;
}
template<typename T>
void binary_search_tree<T>::print_values(){ // prints the values in the tree, from min to max
   print_values(root);
}
 template<typename T>
void binary_search_tree<T>::print_values(node<T>* root){ // prints the values in the tree, from min to max
    if(root == nullptr)
        return;
    cout<<root->data<<endl;
    print_values(root->left);
    print_values(root->right);
}
template<typename T>
void binary_search_tree<T>::delete_tree(){
       delete_tree(root);
        root = nullptr;
}
 template<typename T>
void binary_search_tree<T>::delete_tree(node<T>* node){
    if (node == nullptr)
        return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}
template<typename T>
bool binary_search_tree<T>::is_in_tree(T val){ // returns true if given value exists in the tree
    if(is_in_tree(val, root)==nullptr)
        return false;
    else
        return true;
}
 template<typename T>
node<T>* binary_search_tree<T>::is_in_tree(T val, node<T>* n){ // returns true if given value exists in the tree
    if(n == nullptr)
        return nullptr;
    if(n->data == val)
        return n;
    else if (n->data>val)
        return is_in_tree(val, n->left);
    else
        return is_in_tree(val, n->right);
}
template<typename T>
int binary_search_tree<T>::get_height(){ // returns the height in nodes (single node's height is 1)
   return get_height(root);
}
 template<typename T>
int binary_search_tree<T>::get_height(node<T>* n){ // returns the height in nodes (single node's height is 1)
    if (n == nullptr)
        return -1;
    return max(get_height(n->left), get_height(n->right))+1;
}
 template<typename T>
T binary_search_tree<T>::get_min(){ // returns the minimum value stored in the tree
    node<T> * curr = root;
    while (curr->left != nullptr){
        curr = curr ->left;
    }
    return curr->data;
}
 template<typename T>
T binary_search_tree<T>::get_max(){ // returns the maximum value stored in the tree
    node<T> * curr = root;
    while (curr->right != nullptr){
        curr = curr ->right;
    }
    return curr->data;
}
 template<typename T>
bool binary_search_tree<T>::is_binary_search_tree(node<T> * root){
    if(root == nullptr)
        return true;
    node<T>* l= root->left, *r=root->right;
    if(r!= nullptr && root->data>r->data)
        return false;
    else if(l!= nullptr && root->data<l->data)
        return false;
    return is_binary_search_tree(root->left) && is_binary_search_tree(root->right)&& true;
}
 template<typename T>
void binary_search_tree<T>::delete_value(T d){
    if(d==root->data){
        node<T>* left_branch = root->left;
        node<T>* right_branch = root->right, *prev=right_branch;
        //find the min in right branch
        while(right_branch->left!=nullptr){
            prev= right_branch;
            right_branch = right_branch->left;
        }
        prev->left=nullptr;
        root = right_branch;
        root->left = left_branch;
        root->right = prev;
    }
    else{
        node<T>* n= is_in_tree(d,root);
        if(n->left==nullptr && n->right==nullptr){ //leaf
            node<T>* p= get_parent(d,root), *pl=p->left, *pr=p->right;
            if(pl->data==d)
                p->left = nullptr;
            else if(pr->data==d)
                p->right = nullptr;
        }
        else if(n->left==nullptr){//one child
            node<T>* p= get_parent(d,root), *pl=p->left, *pr=p->right;
            if(pl->data==d)
                p->left = n->right;
            else if(pr->data==d)
                p->right = n->right;
        }
        else if(n->right==nullptr){//one child
            node<T>* p= get_parent(d,root), *pl=p->left, *pr=p->right;
            if(pl->data==d)
                p->left = n->left;
            else if(pr->data==d)
                p->right = n->left;
        }
        else{ //2 children
            node<T>* left_branch = n->left;
            node<T>* right_branch = n->right, *prev=right_branch;
            //find the min in right branch
            while(right_branch->left!=nullptr){
                prev= right_branch;
                right_branch = right_branch->left;
            }
            prev->left=nullptr;
            if(prev == right_branch || prev==left_branch)
                prev = nullptr;
            n = right_branch;
            n->left = left_branch;
            n->right = prev;
            node<T>* p= get_parent(d,root), *pl=p->left, *pr=p->right;
            if(pl->data==d)
                p->left = n;
            else if(pr->data==d)
                p->right = n;
        }
    }

}
 template<typename T>
T binary_search_tree<T>::get_successor(T val){ // returns next-highest value in tree after given value, -1 if none
    node<T> * curr = root, *prev =root;
    //find the node
    while(true){
    if(curr->data == val)
        break;
    else if (curr->data>val){
        prev= curr;
        curr = curr->left;
    }
    else{
        prev= curr;
        curr = curr->right;
    }
    }
    if(curr->right == nullptr){
        if(prev->data>val)
            return prev->data;
        else
            return -1;
    }
    curr = curr->right;
    return curr->data;
}

template<typename T>
node<T>* binary_search_tree<T>::get_root(){
    return root;
}

template<typename T>
node<T>* binary_search_tree<T>::get_parent(T val, node<T>* curr){ // returns next-highest value in tree after given value, -1 if none
   node<T> * curr_l = curr->left, *curr_r=curr->right;
   //find the node
   if (curr_l->data ==val)
       return curr;
   if(curr_r->data ==  val)
       return curr;
   if(val<curr_l->data && val<curr_r->data)
       return get_parent(val, curr_l);
   if (val>curr_r->data)
       return get_parent(val, curr_r);
}
