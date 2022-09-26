#include<bits/stdc++.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node* next;
};

template<class T>
class queue_LL
{
    node<T>* start;
    node<T>* end;

    public:

    queue_LL():start(nullptr),end(nullptr) {}

    // void enqueue(T value)
    // {
    //     node<T>* new_node=new node<T>;
    //     new_node->data=value;
    //     new_node->next=nullptr;

    //     if(start==nullptr)
    //     {
    //         start=new_node;
    //         end=new_node;
    //         return;
    //     }
    //     else
    //     {
    //         end->next=new_node;
    //         end=new_node;
    //     }
    // }

    // void dequeue()
    // {
    //     node<T>* trash;
    //     if(start==nullptr)
    //     cout<<"Underflow"<<endl;
    //     else
    //     {
    //         trash=start;
    //         cout<<"Dequeued elemet is: "<<trash->data<<endl;
    //         start=start->next;
    //         delete trash;
    //     }
    // }

    // void print()
    // {
    //     if(start==nullptr)
    //     cout<<"Queue is empty"<<endl;
    //     else
    //     {
    //         cout<<"Entered queue is:"<<endl;
    //         node<T>* iterate=start;
    //         while(iterate!=nullptr)
    //         {
    //             cout<<iterate->data<<endl;
    //             iterate->next;
    //         }
    //     }
    // }

    void enqueue(T value)
    {
        node<T>* new_node=new node<T>;
        new_node->data=value;
        new_node->next=nullptr;

        if(start==nullptr)
        {
            start=new_node;
            end=new_node;
        }
        else
        {
            end->next=new_node;
            end=new_node;
            end->next=nullptr;
        }
    }

    void print()
    {
        cout<<"Entered queue is:"<<endl;
        if(start==nullptr)
        cout<<"Queue is empty"<<endl;
        else
        {
            node<T>* temp=start;
            while(temp!=nullptr)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }

    void dequeue()
    {
        node<T>* trash;
        if(start==nullptr)
        cout<<"Underflow"<<endl;
        // else if(start==end)
        // {
        //     trash=start;
        //     start=end=nullptr;
        //     delete trash;
        // }
        else
        {
            trash=start;
            cout<<"Dequeued element is: "<<trash->data<<endl;
            start=start->next;
            delete trash;
        }
    }
};

int main()
{
    queue_LL<int> queue;
    int n,value;
    cout<<"Enter number of elemnets to be enqueued:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter a value:"<<endl;
        cin>>value;
        queue.enqueue(value);
    }
    queue.print();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.print();
}