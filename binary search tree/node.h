#ifndef NODE_H
#define NODE_H

template<typename T>
class node
{
public:
    T data;
    node * right, * left;
    node();
    node(T d);
};

#endif // NODE_H
