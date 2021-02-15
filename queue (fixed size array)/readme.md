## Example

    queue_t<int> q;
    for (int i=0;i<=5;i++){
        q.enqueue(i);
    }
    for (int i=0;i<=6;i++){
    cout << q.dequeue()<< endl;
    }
