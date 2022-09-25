#include<bits/stdc++.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node* next;
    struct node* prev;
};

template<class T>
class linkedlist
{
    node<T>* head=nullptr;
    node<T>* tail=nullptr;

    public:

    void createNode(int value)
    {
        node<T>* new_node= new node<T>;
        new_node->data=value;
        new_node->prev=nullptr;
        new_node->next=nullptr;

        if(head==nullptr)
        {
            head=new_node;
            tail=new_node;
        }
        else
        {
            new_node->prev=tail;
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

    void push(T value)
    {
        node<T>* new_node=new node<T>;
        new_node->prev=nullptr;
        head->prev=new_node;
        new_node->data=value;
        new_node->next=head;
        head=new_node;
    }

    void insert(int pos, T value)
    {
        node<T>* temp=head;
        node<T>* new_node=new node<T>;
        new_node->data=value;
        if(pos==1)
        {
            void push(T value);
        }
        else
        {
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            new_node->prev=temp;
            new_node->next=temp->next;
            temp->next->prev=new_node;
            temp->next=new_node;
        }
    }

    void delete_node(int pos)
    {
        node<T>* temp=head;
        node<T>* trash=nullptr;
        if(pos==1)
        {
            trash=head;
            head=head->next;
            head->prev=nullptr;
            delete trash;
        }
        else
        {
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            trash=temp->next;
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
            delete trash;
        }
    }

    void reverse_traverse()
    {
        node<T>* temp=tail;
        cout<<"Reversed linked list is:"<<endl;
        while(temp!=nullptr)
        {
            cout<<temp->data<<endl;
            temp=temp->prev;
        }
    }

    void search(int value)
    {
        node<T>* temp=head;
        int i=1,flag=1;
        while(temp!=nullptr)
        {
            if(temp->data==value)
            {
                cout<<"Value found at position: "<<i;
                flag=0;
                break;
            }
            else
            {
                temp=temp->next;
                i++;
            }
        }
        if(flag)
        {
            cout<<"Value not found"<<endl;
        }
    }
};

int main()
{
    linkedlist<int> list;
    int value,count;
    cout<<"Enter number of nodes to be created:"<<endl;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cout<<"Enter a value:"<<endl;
        cin>>value;
        list.createNode(value);
    }
    list.traverse();
    list.push(20);
    list.traverse();
    list.insert(2,90);
    list.traverse();
    list.delete_node(2);
    list.traverse();
    list.reverse_traverse();
    list.search(3);
}