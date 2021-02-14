#ifndef STACKT_H
#define STACKT_H

#define MAX 1000

template <typename t>
class stackt
{
private:
    t * s;
    int c;
public:
    stackt();
    bool is_empty();
    t pop();
    void push(t val);
    int size();
    t top();
};

#endif // STACKT_H
