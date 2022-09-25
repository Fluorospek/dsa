#include<bits/stdc++.h>
using namespace std;

template<class T>
class queue_circular
{
    int front,rear,size;
    T* queue;

    bool isEmpty()
    {
        return (front==-1);
    }

    bool Overflow()
    {
        return ((rear+1)%size==front);
    }

    bool Underflow()
    {
        return(front%size==rear);
    }

    public:

    queue_circular(T size):front(-1),rear(-1)
    {
        this->size=size;
        queue=new T[size];
    }

    void enqueue(T value)
    {
        if(Overflow())
        {
            cout<<"Overflow"<<endl;
        }
        else if(isEmpty())
        {
            front=rear=0;
            queue[rear]=value;
        }
        else
        {
            rear=(rear+1)%size;
            queue[rear]=value;
        }
    }

    void print()
    {
        cout<<"Elements in the queue are:"<<endl;
        int temp=front;
        do
        {
            cout<<queue[temp]<<endl;
            temp=(temp+1)%size;
        }while(temp!=(rear+1)%size);
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else if(Underflow())
        {
            cout<<"Underflow"<<endl;
            front=rear=-1;
        }
        else
        {
            cout<<"Dequeued element is: "<<queue[front]<<endl;
            front=(front+1)%size;
        }
    }
};

int main()
{
    int n,value;
    cout<<"Enter size of queue to be created:"<<endl;
    cin>>n;
    queue_circular<int> queue(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter a value:"<<endl;
        cin>>value;
        queue.enqueue(value);
    }
    queue.print();
    queue.dequeue();
    queue.dequeue();
    queue.print();
    queue.enqueue(100);
    queue.print();
}