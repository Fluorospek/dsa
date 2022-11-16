#include <bits/stdc++.h>
using namespace std;

template <class T>
class queue_class
{
    T *queue;
    int size, start, end;

    bool isEmpty()
    {
        return (start == -1 || start == end + 1);
    }

    bool isFull()
    {
        return (end == size - 1 && start == 0);
    }

public:
    queue_class(int size)
    {
        this->size = size;
        queue = new T[size];
        start = -1;
        end = -1;
    }

    void enqueue(T value)
    {
        if (isEmpty())
        {
            start = 0;
            end = 0;
            queue[end] = value;
        }
        else if (isFull())
            cout << "Overflow" << endl;
        else
        {
            end++;
            queue[end] = value;
        }
    }

    void dequeue()
    {
        if (isEmpty())
            cout << "Underflow" << endl;
        else
        {
            cout << "Element being dequed is: " << queue[start] << endl;
            start++;
        }
    }

    void print()
    {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
        {
            cout << "Entered queue is:" << endl;
            for (int i = start; i <= end; i++)
                cout << queue[i] << endl;
        }
    }

    void peak()
    {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
            cout << "The first element in the queue is: " << queue[start] << endl;
    }
};

int main()
{
    int n, value;
    cout << "Enter the size of the queue:" << endl;
    cin >> n;
    queue_class<int> queue(n);
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter element to be queued:" << endl;
        cin >> value;
        queue.enqueue(value);
    }
    // queue.enqueue(100);
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    queue.print();
    queue.peak();
}