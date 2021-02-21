#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#define MAX 10000

template<typename T>
class hash_table
{//using linear probing
private:
    int s;
    T * arr;
public:
    hash_table();
    int hash(T k); // - m is size of hash table
    void add(int key, T value);// - if key already exists, update value
    bool exists(int key);
    T get(int key);
    void remove(int key);
    void traverse();
};

#endif // HASH_TABLE_H
