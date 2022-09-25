#include<bits/stdc++.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node* next;
};

template<class T>
class linkedlist
{
    node<T>* head=nullptr;
    node<T>* tail=nullptr;

    public:

    void createnode(T value)
    {
        node<T>* new_node=new node<T>;
        new_node->data=value;
        new_node->next=nullptr;
        if(head==nullptr)
        {
            head=new_node;
            tail=new_node;
        }
        else
        {
            tail->next=new_node;
            tail=new_node;
        }
    }

    void traverse()
    {
        node<T>* temp=head;
        cout<<"Entered linked list is:"<<endl;
        while(temp!=nullptr)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }

    void create_end(T value)
    {
        node<T>* new_node=new node<T>;
        new_node->data=value;
        new_node->next=nullptr;
        if(head==nullptr)
        {
            head=new_node;
            tail=new_node;
        }
        else
        {
            tail->next=new_node;
            tail=new_node;
        }
    }

    void insert(int pos, T value)
    {
        if(pos==1)
        createnode(value);
        else
        {
            node<T>* new_node=new node<T>;
            node<T>* temp=head;
            new_node->data=value;
            new_node->next=nullptr;

            for(int i=1;i<pos-1;i++)
            temp=temp->next;

            new_node->next=temp->next;
            temp->next=new_node;
        }
    }

    void delete_node(int pos)
    {
        if(pos==1)
        head=head->next;
        else
        {
            node<T>* temp=head;
            for(int i=1;i<pos-1;i++)
            temp=temp->next;
            node<T>* trash=temp->next;
            temp->next=temp->next->next;
            delete trash;
        }
    }

    void delete_end()
    {
        node<T>* temp=head;
        while(temp->next->next!=nullptr)
        temp=temp->next;
        node<T>* trash=temp->next;
        temp->next=nullptr;
        delete trash;
    }

    void reverse()
    {
        node<T>* prev=nullptr;
        node<T>* next=nullptr;
        node<T>* curr=head;
        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
    }
};

int main()
{
    linkedlist<int> list;
    int n,value;
    cout<<"Enter number of nodes to be created:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter a value: "<<endl;
        cin>>value;
        list.createnode(value);
    }
    list.traverse();

    list.insert(3,100);
    list.traverse();
    list.delete_node(3);
    list.traverse();
    list.delete_end();
    list.traverse();
}