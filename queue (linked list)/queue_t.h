#ifndef QUEUE_T_H
#define QUEUE_T_H
#define MAX 10000
template<typename T>
class queue_t
{

private:
    T * q;
    int s;
public:
    queue_t();
    bool enqueue(T value);// adds item at end of available storage
    T dequeue();//returns value and removes least recently added element
    bool is_empty();
    bool is_full();
};

#endif // QUEUE_T_H
