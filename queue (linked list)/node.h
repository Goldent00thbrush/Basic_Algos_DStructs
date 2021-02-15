#ifndef NODE_H
#define NODE_H

template<typename t>
class Node
{
public:
    t value;
    Node * next, *prev;
    Node();
};

#endif // NODE_H
